#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1001;
int n, height[MAX], dp[MAX];
//dp一下就行了。。。
int main() 
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	height[0] = 0;
	while (scanf( "%d", &n ) && n != 0)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i ++)
			scanf( "%d", &height[i] );

		for (int i = 1; i <= n; i ++)
		{
			for (int j = 0; j < i; j ++)
			{
				if ((dp[j] & 1) && height[i] < height[j])
					dp[i] = max(dp[i], dp[j] + 1);
				if (!(dp[j] & 1) && height[i] > height[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		printf( "%d\n", dp[n] );
	}
	    
	return 0;
}
