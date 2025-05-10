#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;


int main() {
    const char* const str = "-123576";
    int start = 0;
    for (char i = str[start]; i != '\0'; i = str[++start]) cout << i << endl;
    return 0;
}