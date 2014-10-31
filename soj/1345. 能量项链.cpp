#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 210;
int n, ans, temp, a[MAX], dp[MAX][MAX], head[2*MAX], tail[2*MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d", &a[i] );
			a[i+n] = a[i];
		}

		for (int i = 1; i < 2*n; i ++)
		{
			head[i] = a[i-1];
			tail[i] = a[i];
		}

		for (int len = 2; len <= n; len ++)
		{
			for (int i = 1; i < 2*n-1; i ++)
			{
				int j = i + len - 1;
				if (j > 2*n-1)
					break;
				temp = 0;
				for (int k = i; k <= j-1; k ++)
				{
					if (temp < dp[i][k] + dp[k+1][j] + head[i]*tail[k]*tail[j])
						temp = dp[i][k] + dp[k+1][j] + head[i]*tail[k]*tail[j];			
				}
				dp[i][j] = temp;
			}
		}

		ans = dp[1][n];
		for (int i = 2; i <= n; i ++)
			if (dp[i][i+n-1] > ans)
				ans = dp[i][i+n-1];
		printf( "%d\n", ans );
	}

    return 0;
}
