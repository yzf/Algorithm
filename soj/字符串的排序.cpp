#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    freopen("input", "r", stdin);

    string str;
    while (cin >> str) {
        sort(str.begin(), str.end());
        do {
            printf("%s\n", str.c_str());
        } while (next_permutation(str.begin(), str.end()));
    }

    return 0;
}
