#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main()
{   
    mt19937 mt(time(nullptr));
    int n, K;
    vector<int> a;
    cin >> n >> K;
    for (int i = 0; i < n; ++i)
        a.push_back(mt() % K);

    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    
    int count[K] = {0};
    for (int i = 0; i < n; ++i)
        count[a[i]]++;

    int pref[K] = {0};
    for (int i = 1; i < K; ++i)
        pref[i] = pref[i-1] + count[i];


    while (1) {
        int l, r;
        cin >> l >> r;
        
        r = min(r, K-1);
        l = max(l, 0);

        cout << pref[r] - pref[l-1] << endl;
    }
    return 0;
}