#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (cin >> str) {
		sort(str.begin(), str.end());
		do {
			cout << str << endl;
		} while (next_permutation(str.begin(), str.end())); 
	}

    return 0;
}                                 