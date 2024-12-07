#include <iostream>
#include <random>
using namespace std;

void print_array(vector<int>arr){
    for (int elem: arr){
        cout << elem << " ";
    }
    cout << endl;
}

vector<int> RandArray(int size, double max){
    mt19937 mt(time(nullptr));
    vector<int> a;
    for (int i = 0; i < size; ++i)
        a.push_back((mt() % (int)max));
    return a;
};

int Merge(vector<int>& A, int p, int q, int r){   // p - firstElemIndex, q - divider, r - lastElemIndex
    int n1 = q - p + 1;
    vector<int> L;
    for (int i = 0; i < n1; ++i){
        L.push_back(A[p + i]);
    }
    int n2 = r - q;
    vector<int> R;
    for (int i = 0; i < n2; ++i){
        R.push_back(A[q + i + 1]);
    }
    int i = 0, j = 0, k = p, pairs = 0;

    while (i < n1 && j < n2){
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
            pairs += n1 - i; // If elem from L (L1) > elem form R (R1) =>> all elems from L, which > L1 =>> R1
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

    return pairs;
    
}

int Merge_Sort(vector<int>& A, int p, int r){
    int pairs = 0;
    if (p < r) {
        int q = (p + r)/2;
        pairs += Merge_Sort(A, p, q);
        pairs += Merge_Sort(A, q+1, r);
        pairs += Merge(A, p, q, r);
    }
    return pairs;
}

int InterestingPairs(vector<int>& A){
    int count = 0;
    for (int i = 0; i < A.size() - 1; ++i){
        for (int j = i + 1; j < A.size(); ++j){
            if (A[i] > A[j]){
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    int size = pow(10, 3);
    vector<int>A = RandArray(size, pow(2, 32));
    vector<int>dublicate(A.begin(), A.end());
    int pairs = Merge_Sort(A, 0, size-1);
    int pairs_check = InterestingPairs(dublicate);
    cout << "Найдено " << pairs << " пар с помощью MergeSort" << endl;   
    cout << "Найдено " << pairs_check << " пар с помощью N^2" << endl; 
}