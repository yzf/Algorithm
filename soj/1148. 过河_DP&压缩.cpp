#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool flag[10000];
int l, s, t, m, dist, ans;
int stone[101], a[101], dp[10000];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d%d%d%d", &l, &s, &t, &m );
	
	for (int i = 1; i <= m; i ++)
		scanf( "%d", &stone[i] );

	if (s == t)
	{
		ans = 0;
		for (int i = 1; i <= m; i ++)
			if (stone[i] % s == 0)
				ans ++;
		printf( "%d\n", ans );
	}
	else
	{
		memset(flag, false, sizeof(flag));
		memset(a, 0, sizeof(a));
		memset(dp, -1, sizeof(dp));
		//把石子的位置进行压缩
		dist = t * (t-1) + 10;//对于互质的两个数n,m，大于n*m的数都能用n与m的线性组合表示，+10为了确保压缩不出错；不加数WA
		stone[0] = 0;
		sort(stone, stone+m+1);
		for (int i = 1; i <= m; i ++)
			if (stone[i] - stone[i-1] > dist)
				a[i] = a[i-1] + dist;
			else
				a[i] = a[i-1] + stone[i] - stone[i-1];

		for (int i = 1; i <= m; i ++)
			flag[ a[i] ] = true;//标记石子位置

		int en = min(a[m]+dist, l);
		dp[0] = 0;//初始化
		for (int i = 1; i < s; i ++)
			dp[i] = 1000000;//不可能到达的点开个大数给它
		for (int i = s; i <= en; i ++)//动态规划
		{
			for (int j = i-t; j <= i-s; j ++)
			{
				if (j < 0)	continue;
				if (dp[i] < 0 || (dp[j] + flag[i] < dp[i]))
					dp[i] = dp[j] + flag[i];
			}
		}

		printf( "%d\n", dp[en] );
	}

	return 0;
}
