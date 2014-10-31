#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo = 1 << 30;
const int MAX = 210;
int t, len, i, j, k, m;
int dp[MAX][MAX];
char str1[MAX], str2[MAX];

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &t );
	while (t --) {

		scanf( "%s", str1 );
		
		len = 0;
		for (i = 0; i < strlen(str1); i ++) {//把字符压缩
			if (str1[i] != str1[i + 1]) {
				str2[++ len] = str1[i];
			}
		}

		for (i = 1; i <= len; i ++) {
			dp[i][i] = 1;
		}
		for (k = 1; k < len; k ++) {//k+1为长度
			for (i = 1; i <= len - k; i ++) {
				j = i + k;
				if (str2[i] == str2[j]) {//s[i] == s[j]时，dp[i][j] = dp[i][j - 1]
					dp[i][j] = dp[i][j - 1];
				}
				else {//s[i] != s[j]时，dp[i][j] = min(dp[i][m] + dp[m + 1][j]) (i <= m < j)
					int temp = oo;
					for (m = i; m < j; m ++) {
						temp = min(temp, dp[i][m] + dp[m + 1][j]);
					}
					dp[i][j] = temp;
				}
			}
		}
		
		printf( "%d\n", dp[1][len] );
	}

    return 0;  
} 
