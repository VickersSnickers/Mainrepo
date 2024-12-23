#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void print_vector(vector<int> v){
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

void rand_vector(vector<int>& v, int size, double max){
    mt19937 mt(time(nullptr));
    for (int i = 0; i < size; ++i)
        v[i] = (mt() % (int)max);
};

void MAX_HEAPIFY(vector<int>& A, int i, int heapsize){
    int l = 3*i + 1;
    int m = 3*i + 2;
    int r = 3*i + 3;
    int largest = i;
    if (l < heapsize && A[l] > A[largest]){
        largest = l;
    }
    if (m < heapsize && A[m] > A[largest]) {
        largest = m;
    }
    if (r < heapsize && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        MAX_HEAPIFY(A, largest, heapsize);
    }
}

void BUILD_MAX_HEAP(vector<int>& A){
    int size = A.size();
    for (int i = size/3 - 1; i >= 0; --i){
        MAX_HEAPIFY(A, i, A.size());
    }
}

void heapsort(vector<int>& A){
    BUILD_MAX_HEAP(A);
    int size = A.size();
    for (int i = size; i >= 2; --i){
        swap(A[0], A[i-1]);
        --size;
        MAX_HEAPIFY(A, 0, size);
    }
}

void time_elapsed(int count){
    vector<int>* v1 = new vector<int>(count);
    rand_vector(*v1, count, pow(2, 32));
    vector<int>* v2 = new vector<int>(count);
    for (int i = 0; i < (*v1).size(); ++i){
        (*v2)[i] = (*v1)[i];
    }

    auto start = steady_clock::now();
    heapsort(*v1);
    auto end = steady_clock::now();
    duration<double> elapsed_second = end-start;
    cout << "Heapsort elapsed seconds: " << elapsed_second.count() << endl;
    cout << endl;
    delete v1;

    start = steady_clock::now();
    sort((*v2).begin(), (*v2).end());
    end = steady_clock::now();
    elapsed_second = end-start;
    cout << "sort elapsed seconds: " << elapsed_second.count() << endl;
    cout << endl;
    delete v2;
};

int main() {
    cout << fixed;
    for (int i = 3; i <= 8; ++i){
        time_elapsed(pow(10, i));
        cout << endl;
    }
}