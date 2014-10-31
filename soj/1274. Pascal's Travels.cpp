#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long dp[40][40];
int n;
int a[40][40];
char num[40];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) && n != -1)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i ++)
		{
			scanf( "%s", num );
			for (int j = 0; j < n; j ++)
				a[i][j+1] = num[j] - '0';
		}

		dp[1][1] = 1;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
			{
				if (i+j == n+n)
					continue;
				if (i+a[i][j] > 0 && i+a[i][j] <= n)
					dp[ i+a[i][j] ][j] += dp[i][j];
				if (j+a[i][j] > 0 && j+a[i][j] <= n)
					dp[i][ j+a[i][j] ] += dp[i][j];
			}

		printf( "%lld\n", dp[n][n] );
	}

    return 0;
}

