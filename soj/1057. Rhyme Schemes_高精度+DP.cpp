#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 60;
int n, temp[1000];
string dp[MAX][MAX];
string ans;
//大数乘小数
string mul(string num1, int num2)
{
	memset(temp, 0, sizeof(temp));
	string result;
	int len = num1.length(), i;
	reverse(num1.begin(), num1.end());
	for (i = 0; i < len; i ++) {
		temp[i] = (num1[i] - '0') * num2;
	}
	for (i = 0; i < len+2; i ++) {
		temp[i+1] += (temp[i] / 10);
		temp[i] %= 10;
	}
	for (i = len+2; i >= 0; i --) {
		if (temp[i] != 0) {
			break;
		}
	}
	for (; i >= 0; i --) {
		result.push_back(temp[i] + '0');
	}
	return result;
}
//大数+大数
string add(string num1, string num2)
{
	memset(temp, 0, sizeof(temp));
	string result;
	int i, len1 = num1.length(), len2 = num2.length();
	int maxlen = max(len1, len2);
	int minlen = min(len1, len2);
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (i = 0; i < minlen; i ++) {
		temp[i] = (num1[i] - '0') + (num2[i] - '0');
	}
	for (i = minlen; i < maxlen; i ++) {
		if (len1 == maxlen) {
			temp[i] = num1[i] - '0';
		}
		else {
			temp[i] = num2[i] - '0';
		}
	}
	for (i = 0; i < maxlen+2; i ++) {
		temp[i+1] += (temp[i] / 10);
		temp[i] %= 10;
	}
	for (i = maxlen+2; i >= 0; i --) {
		if (temp[i] != 0) {
			break;
		}
	}
	for (; i >= 0; i --) {
		result.push_back(temp[i] + '0');
	}
	return result;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	dp[0][0] = "1";
	for (int i = 1; i <= 50; i ++) {
		dp[0][i] = "0";
	}
	for (int i = 1; i <= 50; i ++) {
		for (int j = 1; j <= 50; j ++) {
			dp[i][j] = add(dp[i-1][j-1], mul(dp[i-1][j], j));
		}
	}

	while (cin >> n && n) {
		ans = "0";
		for (int i = 1; i <= n; i ++) {
			ans = add(ans, dp[n][i]);
		}
		cout << n << " " << ans << endl;
	}

    return 0;
}
/*
aaaa, 
aaab, aaba, abaa, 
aabb, abab, abba, aabc, abac, abca, 
abbb, abbc, abcb, abcc, abcd.
状态转移方程：
设 f [ i ][ j ] 表示 i 行诗中一共用 j 种韵数的总押韵方案。
 f [ i ][ j ] = f [ i - 1 ][ j - 1 ] + f [ i - 1 ][ j ] * j 
因此，i 行诗总共的押韵方案 ans ＝ ans + f [ i ][ j ] ,  ( 1 <= j <= i ) 
*/
