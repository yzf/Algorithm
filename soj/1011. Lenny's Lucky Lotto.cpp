#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cases, n, m;
long long dp[11][2001], ans;


int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	for (int caseNum = 1; caseNum <= cases; caseNum ++)
	{
		memset(dp, 0, sizeof(dp));
		
		scanf( "%d%d", &n, &m );

		for (int i = 1; i <= m; i ++)
			dp[1][i] = 1;
		for (int len = 2; len <= n; len ++)
			for (int j = 1; j <= m; j ++)
			{
				if (j%2 == 0)
					dp[len][j] = dp[len][j-1] + dp[len-1][j/2];
				else
					dp[len][j] = dp[len][j-1];
			}

		ans = dp[n][1];
		for (int i = 2; i <= m; i ++)
			ans += dp[n][i];
		printf( "Case %d: n = %d, m = %d, # lists = %lld\n", caseNum, n, m, ans );
	}

	return 0;
}
/*
DP，f[i][j]表示分为i个数，且最大数为j时的最多方案数，
则可以得到递推公式f[i][j]=∑f[i-1][k](k∈[1..j/2])
在这个公式下时间复杂度应该是O（nm2），

其实有个点是比较容易发现的，
就是f[i][j]和f[i][j-1]的差别其实是很小的，
而且差值和j有关系，但j为偶数的时候两者相差f[i-1][j/2]，
当j为奇数时，两者相同，这样的话就可以将复杂度降为O（nm）
*/
