#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int MAX = 110;
const int oo = 1 << 30;

int dp[MAX][MAX];
string str, tmp;
map<string, bool> flag;
int n;
/*
dp[i][j] = min(dp[i][i + k] + dp[i + k + 1][j])
dp[i][i + k] != oo && dp[i + k + 1][j] != oo
(0 <= k <= j - i - 1)
*/
int main()  
{  
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	
	cin >> str;
	cin >> n;
	int len = str.length();
	for (int i = 0; i < n; i ++) {
		cin >> tmp;
		flag[tmp] = true;
	}

	for (int i = 0; i < len; i ++)
		for (int j = 0; j < len; j ++)
			dp[i][j] = oo;

	for (int k = 0; k < len; k ++) {
		for (int i = 0; i < len - k; i ++) {
			int j = i + k;
			tmp = str.substr(i, k + 1);
			if (flag[tmp]) {
				dp[i][j] = 1;
				continue;
			}
			for (int l = 0; l < j - i; l ++) {
				if (dp[i][i + l] != oo && dp[i + l + 1][j] != oo) {
					dp[i][j] = min(dp[i][j], dp[i][i + l] + dp[i + l + 1][j]);
				}
			}
		}
	}

	cout << dp[0][len - 1] << endl;


    return 0;  
} 
