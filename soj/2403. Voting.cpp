#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

string str;
int cn[4];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (cin >> str) {
		if (str == "#") {
			break;
		}

		memset(cn, 0, sizeof(cn));
		int i;
		int len = str.length();
		for (i = 0; i < len; i ++) {
			if (str[i] == 'Y') {
				cn[0] ++;
			}
			else if (str[i] == 'N') {
				cn[1] ++;
			}
			else if (str[i] == 'P') {
				cn[2] ++;
			}
			else {
				cn[3] ++;
			}
		}
		if (cn[3] >= ceil((double)len/2.0)) {
			cout << "need quorum\n";
			continue;
		}
		if (cn[0] > cn[1]) {
			cout << "yes\n";
		}
		else if (cn[0] < cn[1]) {
			cout << "no\n";
		}
		else {
			cout << "tie\n";
		}
	}
	
	return 0;
}
