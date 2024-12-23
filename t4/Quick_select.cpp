#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v){
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int partition(int* input, int p, int r) {
    int pivot = input[r];
    while (p < r) {
        while (input[p] < pivot)
            p++;
        
        while (input[r] > pivot)
            r--;
        
        if (input[p] == input[r])
            p++;
        else if (p < r) {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    return r;
}

int quick_select(int* input, int p, int r, int k)
{
    if ( p == r ) return input[p];
    int j = partition(input, p, r);
    int length = j - p + 1;
    if ( length == k ) return input[j];
    else if ( k < length ) return quick_select(input, p, j - 1, k);
    else  return quick_select(input, j + 1, r, k - length);
}