#include <bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 gen(rd());

// случайный pivot
inline size_t randomPivot(size_t left, size_t right) {
    uniform_int_distribution<size_t> dist(left, right);
    return dist(gen);
}

void Partition3Groups(vector<int>& arr, size_t left, size_t right, size_t& lt, size_t& gt) {
    size_t ind = randomPivot(left, right);
    int val = arr[ind];
    swap(arr[left], arr[ind]);

    lt = left;  
    gt = right + 1;
    size_t i = left + 1;

    while (i < gt) {
        if (arr[i] < val) {
            swap(arr[i], arr[lt + 1]);
            lt++;
            i++;
        } else if (arr[i] > val) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        } else {
            i++;
        }
    }
    swap(arr[left], arr[lt]);
}

void quicksort(vector<int>& arr, size_t left, size_t right) {
    if (left >= right) return;

    size_t lt, gt;
    Partition3Groups(arr, left, right, lt, gt);

    if (lt > left){
        quicksort(arr, left, lt - 1);
    }
    if (gt < right){ 
        quicksort(arr, gt, right);
    }
}

void quicksort(vector<int>& arr) {
    if (arr.empty()) return;
    quicksort(arr, 0, arr.size() - 1);
}

int main() {
    for (int p = 3; p <= 8; p++) {
        const size_t n = pow(10, p);
        vector<int> arr(n);
        for (size_t i = 0; i < n; i++) {
            arr[i] = rd() % 10000; 
        }
        cout << endl;
        
        vector<int> arr_copy = arr;
        
        auto start = chrono::steady_clock::now();
        quicksort(arr);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_second = end-start;
        cout << "quicksort elapsed seconds: " << elapsed_second.count() << endl;

        start = chrono::steady_clock::now();
        sort(arr_copy.begin(), arr_copy.end());
        end = chrono::steady_clock::now();
        elapsed_second = end-start;
        cout << "std::sort elapsed seconds: " << elapsed_second.count() << endl;
        
        }

    return 0;
}
