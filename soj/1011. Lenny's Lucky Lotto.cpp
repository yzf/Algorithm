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
DP��f[i][j]��ʾ��Ϊi�������������Ϊjʱ����෽������
����Եõ����ƹ�ʽf[i][j]=��f[i-1][k](k��[1..j/2])
�������ʽ��ʱ�临�Ӷ�Ӧ����O��nm2����

��ʵ�и����ǱȽ����׷��ֵģ�
����f[i][j]��f[i][j-1]�Ĳ����ʵ�Ǻ�С�ģ�
���Ҳ�ֵ��j�й�ϵ����jΪż����ʱ���������f[i-1][j/2]��
��jΪ����ʱ��������ͬ�������Ļ��Ϳ��Խ����ӶȽ�ΪO��nm��
*/
