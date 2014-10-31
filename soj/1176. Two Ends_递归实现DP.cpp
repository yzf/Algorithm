#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1000;

int test, n, sum;
int dp[MAX][MAX], a[MAX];

int search(int l, int r)
{
	if (l > r)
		return 0;
	else if (l == r)
		return a[l];
	else if (dp[l][r] != -1)
		return dp[l][r];

	int temp1, temp2;
	temp1 = a[l] + (a[l+1] >= a[r] ? search(l+2, r) : search(l+1, r-1));
	temp2 = a[r] + (a[l] >= a[r-1] ? search(l+1, r-1) : search(l, r-2));
	dp[l][r] = max(temp1, temp2);

	return dp[l][r];
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	test = 0;
	while (scanf( "%d", &n ) && n != 0)
	{
		sum = 0;
		memset(dp, -1, sizeof(dp));
		test ++;
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d", &a[i] );
			sum += a[i];
		}
		search(0, n-1);
		printf( "In game %d, the greedy strategy might lose by as many as %d points.\n", test, 2*dp[0][n-1]-sum );
	}

	return 0;
}

/*
dp[s][t]=max{  card[s]+dp[s+2][t],          ( 玩家1取左端，  剩下的牌左边大）

                      card[s]+dp[s+1][t-1],       ( 玩家1取左端，  剩下的牌右边大）

                      dp[s+1][t-1]+card[t]         ( 玩家1取右端，  剩下的牌左边大）

                      dp[s][t-2]+card[t]             ( 玩家1取右端，  剩下的牌右边大）   }
*/
