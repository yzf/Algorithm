#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 110;
int n;
int dp[MAX];
int need[MAX], price[MAX];
int sum[MAX];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &n ) != EOF) {
		
		int i, j;
		for (i = 1; i <= n; i ++) {
			scanf( "%d", &need[i] );
			sum[i] = sum[i - 1] + need[i];
		}
		for (i = 1; i <= n; i ++) {
			scanf( "%d", &price[i] );
		}

		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i ++) {
			dp[i] = dp[i - 1];
			if (need[i] > 0) {
				dp[i] += price[i] * (need[i] + 10);
			}
			for (j = 0; j < i; j ++) {
				dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10) * price[i]);
			}
		}

		printf( "%d\n", dp[n] );
	}
	
	return 0;
}
