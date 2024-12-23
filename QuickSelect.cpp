#include <bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 gen(rd());

void print_vector(std::vector<int> v){
    for (int i = 0; i < v.size(); ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

// случайный val
inline size_t randomPivot(size_t left, size_t right) {
    uniform_int_distribution<size_t> dist(left, right);
    return dist(gen);
}
int partition(vector<int> &A, int left, int right) {
    int ind = randomPivot(left, right);
    int val = A[ind];

    swap(A[ind], A[right]);
    int stInd = left;

    for (int i = left; i < right; ++i) {
        if (A[i] < val) {
            swap(A[i], A[stInd]);
            stInd++;
        }
    }

    swap(A[stInd], A[right]);
    return stInd;
}
int quickSelect(vector<int> &A, int left, int right, int k) {
    if (left == right) {
        return A[left];
    }

    int ind = partition(A, left, right);
    int length = ind - left + 1;
    if (k == length) {
        return A[ind];
    } else if (k < length) {
        return quickSelect(A, left, ind - 1, k);
    } else {
        return quickSelect(A, ind + 1, right, k - length);
    }
}

void rand_vector(std::vector<int>& v, int size, double max, mt19937 mt){
    for (int i = 0; i < size; ++i)
        v[i] = (mt() % (int)max);
};

int main() {
    int size = 100;
    vector<int> A(size);
    std::mt19937 mt(time(nullptr));
    rand_vector(A, size, 10000, mt);
    vector<int> B;
    B = A;
    int end = A.size();

    // int k;
    // cin >> k;
    // int ans = quickSelect(A, 0, end - 1, k);
    // cout << ans;
    // cout << endl;
    sort(B.begin(), B.end());
    // cout << B[k-1];


    bool flag = true;
    for (int k = 1; k <= size; ++k){
        int ans = quickSelect(A, 0, end-1, k);
        if(ans != B[k-1]) {
            flag = false;
        }
    }
    cout << flag;
    return 0;
}