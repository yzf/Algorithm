#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int MAX = 1001;
string str;
map<string, int> m1;
int n, m;
int i, j;
int l, r;
int cn, len;
int m2[100001], m3[100001];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	cin >> n;
	for (i = 1; i <= n; i ++) {
		cin >> str;
		m1[str] = i;//把字符串转发成数字 
	}

	cin >> m;
	for (i = 1; i <= m; i ++) {
		cin >> str;
		m2[i] = m1[str];
	}

	l = 1;		r = 0;
	cn = len = 0;
	m3[ m2[r] ] ++;
	m3[0] = 100010;
	while (r <= m) {
		r ++;
		if (m3[ m2[r] ] == 0) {
			cn ++;
			len = r - l + 1;
		}
		m3[ m2[r] ] ++;
		
		while (m3[ m2[l] ] > 1 && l <= r) {
			m3[ m2[l] ] --;
			l ++;
			len = min(len, r - l + 1);
		}
	}

	cout << cn << endl << len << endl;
	
	return 0;
}
