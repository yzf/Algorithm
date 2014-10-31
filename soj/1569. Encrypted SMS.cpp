#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

string str;
string ans;
bool flag[110];
map<char, int> group;
int b[8] = {3, 3, 3, 3, 3, 4, 3, 4};
char c[8][4] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, 
				{'M', 'N', 'O'}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, 
				{'W', 'X', 'Y', 'Z'}};

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z') {
		c = c - 'a' + 'A';
	}
}

void toLower(char &c)
{
	if (c >= 'A' && c <= 'Z') {
		c = c + 'a' - 'A';
	}
}

void makeGroup()
{
	int btn = 0, cn = 1;
	for (char c = 'A'; c <= 'O'; c ++) {
		group[c] = btn;
		if (cn ++ % 3 == 0) {
			btn ++;
		}
	}
	for (char c = 'P'; c <= 'S'; c ++) {
		group[c] = btn;
	}
	btn ++;
	for (char c = 'T'; c <= 'V'; c ++) {
		group[c] = btn;
	}
	btn ++;
	for (char c = 'W'; c <= 'Z'; c ++) {
		group[c] = btn;
	}
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	makeGroup();
	while (cin >> str && str != "#") {
		ans = "";
		int i, j, k;
		int len = str.length();
		for (i = 0; i < len; i ++) {
			char cc = str[i];
			if (cc >= 'A' && cc <= 'Z') {
				flag[i] = true;
			}
			else {
				flag[i] = false;
			}
			toUpper(cc);
			j = group[cc];
			k = cc - c[j][0] + 1;
			k = k + 100*b[j] - (i + 1);
			k %= b[j];
			if (k == 0) {
				k = b[j];
			}
			k --;
			ans += c[j][k];
			if (!flag[i]) {
				toLower(ans[i]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}
