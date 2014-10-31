#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m, n, bridge, x, y, a, b; 
long long **dp;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &m, &n ) && m != 0 && n != 0)
	{
		dp = new long long *[m+1];//动态二位数组的申请
		for (int i = 0; i <= m; i ++)
		{
			dp[i] = new long long [n+1];
			memset(dp[i], 0 ,sizeof(long long)*(n+1));
		}

		for (int i = 0; i <= m; i ++)
			dp[i][0] = 1;
		for (int i = 0; i <= n; i ++)
			dp[0][i] = 1;

		scanf( "%d", &bridge );
		while (bridge --)
		{
			scanf( "%d%d%d%d", &x, &y, &a, &b );
			for (int i = x; i < x+a-1; i ++)
				for (int j = y; j < y+b-1; j ++)
					dp[i][j] = -1;
		}
		//动态规划
		for (int i = 1; i <= m; i ++)
			for (int j = 1; j <= n; j ++)
			{
				if(dp[i-1][j] != -1 && dp[i][j] != -1)
					dp[i][j] = dp[i-1][j];
				if(dp[i][j] != -1 && dp[i][j-1] != -1)
					dp[i][j] += dp[i][j-1];
			}
		
		printf( "%lld\n", dp[m][n] );
		for (int i = 0; i <= m; i ++)
			delete dp[i];
	}

	return 0;
}
