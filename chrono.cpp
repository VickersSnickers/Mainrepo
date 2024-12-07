#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace chrono;

int main() {

    mt19937 mt(time(nullptr));
    int size = 100, a[size];
    for (int i = 0; i < size; ++i)
        a[i] = (mt() % 100) + 100;

    auto start = steady_clock::now();           // начало замера
    
    sort(a,  a+size);
    int ans[size];
    int ind1 = 0, ind2 = size - 1;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 1)
            ans[i] = a[ind2--];
        else
            ans[i] = a[ind1++];
    }

    auto end = steady_clock::now();             // конец замера
    duration<double> elapsed_seconds = end - start;
    cout << fixed;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}