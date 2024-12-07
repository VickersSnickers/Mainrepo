#include <iostream>
#include <random>
#include <cmath>
using namespace std;

vector<int> RandArray(int size, double max){
    mt19937 mt(time(nullptr));
    vector<int> a;
    for (int i = 0; i < size; ++i)
        a.push_back((mt() % (int)max));
    return a;
};
