#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 510;
int h, w;
int cn[MAX][MAX];
int dp[MAX][MAX];
int ans;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d%d", &h, &w ) != EOF) {
		int i, j;
		for (i = 1; i <= h; i ++) {
			for (j = 1; j <= w; j ++) {
				scanf( "%d", &cn[i][j] );
			}
		}

		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= h; i ++) {
			for (j = 1; j <= w; j ++) {
				int temp = dp[i - 1][j - 1];
				temp = max(temp, dp[i - 1][j]);
				temp = max(temp, dp[i - 1][j + 1]);
				dp[i][j] = cn[i][j] + temp;
			}
		}

		ans = 0;
		for (i = 1; i <= w; i ++) {
			ans = max(ans, dp[h][i]);
		}
		printf( "%d\n", ans );
	}

	return 0;
}
