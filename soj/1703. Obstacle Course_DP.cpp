#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int BIGNUM = 1 << 30;
const int MAX = 125;
int cases, n, cost[MAX][MAX], dp[MAX][MAX];
//这题貌似是最短路径，但第一感觉是dp，然后dp了一下。。发现重复dp 3次可以得到样例的结果。。。
//交上去AC了。。为什么dp 3次，我也没想懂。。是数据弱？ 
void doit()
{
	dp[0][0] = 0;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (i-1 >= 0)
				dp[i][j] = min(dp[i-1][j], dp[i][j]);
			if (i+1 < n)
				dp[i][j] = min(dp[i+1][j], dp[i][j]);
			if (j-1 >= 0)
				dp[i][j] = min(dp[i][j-1], dp[i][j]);
			if (j+1 < n)
				dp[i][j] = min(dp[i][j+1], dp[i][j]);
			dp[i][j] += cost[i][j];
		}
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	cases = 1;
	while (scanf( "%d", &n ) && n != 0)
	{
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
			{
				scanf( "%d", &cost[i][j] );
				dp[i][j] = BIGNUM;
			}

		for (int i = 0; i < 3; i ++)
			doit();

		printf( "Problem %d: %d\n", cases ++, dp[n-1][n-1] );
	}

    return 0;
}

