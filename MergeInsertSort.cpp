#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

void print_array(int arr[], int size){
    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* RandArray(int size, double max){
    mt19937 mt(time(nullptr));
    int* a = new int[size];
    for (int i = 0; i < size; ++i)
        a[i] = (mt() % (int)max);
    return a;
}

void InsertionSort(int A[], int p, int size) {
    for (int i = p + 1; i < p + size; ++i) {
        int j = i;
        while (j > p && A[j - 1] > A[j]) {
            swap(A[j - 1], A[j]);
            --j;
        }
    }
}

void Merge(int A[], int p, int q, int r){   // p - firstElemIndex, q - divider, r - lastElemIndex
    int n1 = q - p + 1;
    int L[n1] = {};
    for (int i = 0; i < n1; ++i){
        L[i] = A[p + i];
    }
    int n2 = r - q;
    int R[n2] = {};
    for (int i = 0; i < n2; ++i){
        R[i] = A[q + i + 1];
    }
    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2){
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1){
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2){
        A[k] = R[j];
        ++j;
        ++k;
    }
}

void MergeInsert_Sort(int A[], int p, int r, int m){
    int n = r - p + 1;
    if (n <= m) {
        InsertionSort(A, p, n);
    } else {
        int q = (p + r)/2;
        MergeInsert_Sort(A, p, q, m);
        MergeInsert_Sort(A, q+1, r, m);
        Merge(A, p, q, r);
    }
}

void Merge_Sort(int A[], int p, int r, int m){
    int n = r - p + 1;
    if (n <= m) {
        InsertionSort(A, p, n);
    } else {
        int q = (p + r)/2;
        Merge_Sort(A, p, q, m);
        Merge_Sort(A, q+1, r, m);
        Merge(A, p, q, r);
    }
}

duration<double> Elapsed_SecondsInsert(int A[], int size, int m){
    auto start = steady_clock::now();
    MergeInsert_Sort(A, 0, size-1, m);
    auto end = steady_clock::now();
    duration<double> elapsed_seconds = end - start;
    return elapsed_seconds;
}

duration<double> Elapsed_Seconds(int A[], int size, int m){
    auto start = steady_clock::now();
    Merge_Sort(A, 0, size-1, m);
    auto end = steady_clock::now();
    duration<double> elapsed_seconds = end - start;
    return elapsed_seconds;
}

int main() {
    cout << fixed;
    for (int size = pow(10, 3); size < pow(10, 6); size *= 10){
        int *arr = RandArray(size, pow(2, 16));
        int dublicate[size] = {};
        for (int i = 0; i < size; ++i){
            dublicate[i] = arr[i];
        }
        //int m = log2(size);         // оптимальное m
        duration<double> mn(1000);
        int val = 1;
        for (int m = 2; m < 61; ++m){
            duration<double> time = Elapsed_SecondsInsert(arr, size, m) - Elapsed_Seconds(dublicate, size, m);
            if (mn.count() > time.count()){
                mn = time;
                val = m;
            }
        }
        cout << "For N = " << size << ": m = " << val;
        // cout << Elapsed_SecondsInsert(arr, size, m).count() << endl;
        // cout << Elapsed_Seconds(dublicate, size, m).count() << endl;
        cout << endl;
    }
}
