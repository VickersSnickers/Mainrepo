#include <vector>
#include <random>
#include <chrono>
#include <iostream>
using namespace std;

void print_vector(std::vector<int> v){
    for (int i = 0; i < v.size(); ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void rand_vector(std::vector<int>& v, int size, double max){
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < size; ++i)
        v[i] = (mt() % (int)max);
};

int Partition(vector<int>& A, int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j){
        if (A[j] <= x){
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return (i+1);
}

int Randomized_Partition(vector<int>& A, int p, int r){
    int i = p + rand() % (r - p + 1);
    swap(A[r], A[i]);
    return Partition(A, p, r);
}

void Randomized_Quicksort(vector<int>& A, int p, int r){
    if (p < r){
        int q = Randomized_Partition(A, p, r);
        Randomized_Quicksort(A, p, q-1);
        Randomized_Quicksort(A, q+1, r);
    }
}

int main() {
    srand(time(0));
    // vector<int>* v = new vector<int>(100);
    // rand_vector(*v, 100, 1000);
    // print_vector(*v);
    // cout << endl;
    // Randomized_Quicksort(*v, 0, (*v).size() - 1);
    // print_vector(*v);
    // delete v;
}