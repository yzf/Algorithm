#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 210;
int n, a[MAX];
int dp[MAX][MAX];
int result;
/*
dp[i][j] 区间[i, j]的最优值
dp[i][j] = max( dp[i][k] + dp[k][j] + a[i] * a[k] * a[j] ) 
i + 1 <= k <= j - 1
*/

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &n );
	fprintf(stderr, "%d\n", n);
	for (int i = 0; i < n; i ++) {
		scanf( "%d", &a[i] );
		fprintf(stderr, "%d ", a[i]);
		a[n + i] = a[i];
	}
	fprintf(stderr, "\n");

	for (int len = 3; len <= n + 1; len ++) {
		for (int i = 0; i <= 2 * n - len; i ++) {
			int j = i + len - 1;
			int tmp = 0;
			for (int k = i + 1; k <= j - 1; k ++) {
				tmp = max( tmp, dp[i][k] + dp[k][j] + a[i] * a[k] * a[j] );
			}
			dp[i][j] = tmp;
			result = max( result, dp[i][j] );
		}
	}
	printf( "%d\n", result );

    return 0;
}                                 