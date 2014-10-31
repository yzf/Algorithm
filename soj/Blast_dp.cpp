#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int oo = 100000000;
const int MAX = 2010;
int o;
string a, b;
int dp[MAX][MAX];//表示A串前i个和B串前j个的最少距离

int myabs(char x, char y) {
	return x > y ? x - y : y - x;
}

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	cin >> a >> b;
	cin >> o;

	for (int i = 0; i <= a.length(); i ++) 
		for (int j = 0; j <= b.length(); j ++)
			dp[i][j] = oo;
	for (int i = 0; i <= a.length(); i ++) 
		dp[i][0] = i * o;
	for (int i = 0; i <= b.length(); i ++)
		dp[0][i] = i * o;

	for (int i = 1; i <= a.length(); i ++) {
		for (int j = 1; j <= b.length(); j ++) {
			int tmp = min(dp[i - 1][j] + o, dp[i][j - 1] + o);
			tmp = min(tmp, dp[i - 1][j - 1] + myabs(a[i - 1], b[j - 1])); 
			dp[i][j] = tmp;
		}
	}
	cout << dp[a.length()][b.length()] << endl;

    return 0;
}                                 