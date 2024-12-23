#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

vector<int> generator(int N){
    set<int> a;
    for (int p = 0; p < sqrt(N); p++) {
        for (int q = 0; q < sqrt(N); q++) {
            a.insert(pow(2, p) * pow(3, q));
        }
    }
    vector<int> res(a.begin(), a.end());
    return res;
};

vector<int> RandArray(int size, double max){
    mt19937 mt(time(nullptr));
    vector<int> a;
    for (int i = 0; i < size; ++i)
        a.push_back((mt() % (int)max));
    return a;
};

void Shell_Sort(vector<int>& arr, vector<int>& gaps){
    int size = arr.size(), ptr = gaps.size() - 1;
    for (int gap = gaps[ptr]; gap > 0;) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap = gaps[--ptr];
        
    }
};

void time_compare(int count, vector<int> seq){
    vector<int> arr = RandArray(count, pow(2, 32));

    vector<int> dublicate = arr;
    auto start = steady_clock::now();
    sort(dublicate.begin(), dublicate.end());
    auto end = steady_clock::now();
    duration<double> elapsed_second = end-start;
    cout << "std::sort elapsed seconds: " << elapsed_second.count() << endl;

    start = steady_clock::now();
    Shell_Sort(arr, seq);
    end = steady_clock::now();
    elapsed_second = end-start;
    cout << "Shell Sort elapsed seconds: " << elapsed_second.count() << endl;
    cout << endl;
    
};

int main() {
    cout << fixed;
    vector<int> seq = generator(100);

    for (int N = 3; N < 8; ++N){
        cout << "N = 10^" << N << endl;
        time_compare(pow(10, N), seq);
    }
}