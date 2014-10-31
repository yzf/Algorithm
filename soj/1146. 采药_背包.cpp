#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int n, cost, value, ans, T, dp[1001];
bool visited[1001];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	visited[0] = true;
	ans = 0;
	scanf( "%d%d", &T, &n );
	for (int i = 0; i < n; i ++)
	{
		scanf( "%d%d", &cost, &value );
		for (int j = T; j - cost >= 0; j --)
		{
			if (visited[j - cost])
			{
				visited[j] = true;
				if (dp[j - cost] + value > dp[j])
					dp[j] = dp[j - cost] + value;
				if (dp[j] > ans)
					ans = dp[j];
			}
		}
	}
	printf( "%d\n", ans );

	return 0;
}
