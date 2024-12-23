#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

void print_vector(std::vector<int> v){
    for (int i = 0; i < v.size(); ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int getMax(std::vector<int> v) {
    int maximum = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i] > maximum) maximum = v[i];
    return maximum;
}

void countingSort(vector<int>& A, int exp, int base) {
    int n = A.size();
    vector<int> output(n);
    vector<int> count(base, 0);

    for (int i = 0; i < n; i++) {
        int digit = (A[i] / exp) % base;
        count[digit]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % base;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void radixSort(vector<int>& A) {
    int maxElement = getMax(A);
    int base = A.size();

    for (int exp = 1; maxElement / exp > 0; exp *= base) {
        countingSort(A, exp, base);
    }
}

void time_elapsed(int n, mt19937& gen, uniform_int_distribution<int> dist){
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        A[i] = dist(gen);
    }
    vector<int> B = A;

    auto start = chrono::steady_clock::now();
    radixSort(A);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_second = end-start;
    cout << "radixSort elapsed seconds: " << elapsed_second.count() << endl;
    cout << endl;

    start = chrono::steady_clock::now();
    sort(A.begin(), A.end());
    end = chrono::steady_clock::now();
    elapsed_second = end-start;
    cout << "std::sort elapsed seconds: " << elapsed_second.count() << endl;
    cout << endl;
};

int main() {
    cout << fixed;
    int n;
    cout << "Enter n: ";
    cin >> n;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, pow(n, 3) - 1);

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        A[i] = dist(gen);
    }

    vector<int> Acop;
    Acop = A;
    
    radixSort(A);
    sort(Acop.begin(), Acop.end());

    bool flag = true;
    for (int i; i < A.size(); ++i){
        if (A[i] != Acop[i]) flag = false;
    }
    cout << flag;

    return 0;
}
