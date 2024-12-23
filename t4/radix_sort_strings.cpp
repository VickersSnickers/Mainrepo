#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

void print_vector(const vector<string>& v) {
    for (const auto& str : v) {
        cout << str << endl;
    }
    cout << endl;
}

string getMax(const vector<string>& v) {
    string maximum = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i].length() > maximum.length()) maximum = v[i];
    return maximum;
}

string rand_string(int max_val) {
    const string charset = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    int length = rand() % (max_val);

    string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += charset[rand() % charset.size()];
    }

    return randomString;
}

void countingSort(vector<string>& v, int place) {
    const int max = 256;
    vector<string> output(v.size());
    int count[max] = {0};

    for (int i = 0; i < v.size(); i++) {
        char c = (place < v[i].length()) ? v[i][place] : 0;
        count[(int)c]++;
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        char c = (place < v[i].length()) ? v[i][place] : 0;
        output[count[(int)c] - 1] = v[i];
        count[(int)c]--;
    }

    for (int i = 0; i < v.size(); i++) {
        v[i] = output[i];
    }
}


void MSDSort(vector<string>& v, int place = 0) {
    if (v.empty()) return;

    string max = getMax(v);
    if (place >= max.length()) return;
    countingSort(v, place);


    vector<vector<string>> buckets(256);
    for (const string& str : v) {
        char c = (place < str.length()) ? str[place] : 0;
        buckets[(int)c].push_back(str);
    }

    v.clear();
    for (auto& bucket : buckets) {
        if (!bucket.empty()) {
            MSDSort(bucket, place + 1);
            v.insert(v.end(), bucket.begin(), bucket.end());
        }
    }
}

void time_elapsed(int n) {
    vector<string>v1(n);
    for (int i = 0; i < n; ++i) {
        string str = rand_string(pow(10, 7)/n/n);
        v1[i] = str;
    }
    vector<string>v2 = v1;

    auto start = chrono::steady_clock::now();
    MSDSort(v1);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "MSD sort elapsed seconds: " << elapsed_seconds.count() << endl;


    start = chrono::steady_clock::now();
    sort(v2.begin(), v2.end());
    end = chrono::steady_clock::now();
    elapsed_seconds = end - start;
    cout << "std::sort elapsed seconds: " << elapsed_seconds.count() << endl;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<string>v(n);
    for (int i = 0; i < n; ++i) {
        string str = rand_string(pow(10, 4)/n/n);
        v[i] = str;
    }
    vector<string>copv = v;
    MSDSort(v);
    sort(copv.begin(), copv.end());

    bool flag = true;
    for (int i; i < v.size(); ++i){
        if (v[i] != copv[i]) flag = false;
    }
    cout << flag;

    // for (int i = 3; i <= n; ++i){
    //     time_elapsed(pow(10, i));
    // }

    return 0;
}
