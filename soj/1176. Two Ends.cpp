#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1000;

int test, n, sum;
int dp[MAX][MAX], a[MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	test = 0;
	while (scanf( "%d", &n ) && n != 0)
	{
		sum = 0;
		memset(dp, 0, sizeof(dp));
		test ++;
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d", &a[i] );
			sum += a[i];
		}
		for (int i = 0; i < n; i ++)
			dp[i][i] = a[i];
		for (int len = 2; len <= n; len++)
		{
			for (int be = 0; be < n-len+1; be ++)
			{
				int end = be+len-1;
				int temp1 = a[be], temp2 = a[end];
				temp1 += a[be+1] >= a[end] ? dp[be+2][end] : dp[be+1][end-1];
				temp2 += a[be] >= a[end-1] ? dp[be+1][end-1] : dp[be][end-2];
				dp[be][end] = max(temp1, temp2);
			}
		}
		
		printf( "In game %d, the greedy strategy might lose by as many as %d points.\n", test, 2*dp[0][n-1]-sum );
	}

	return 0;
}
