#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
//ƽ������ÿ������8�����ڵ㣬ɾ������Ϊ�Խǵ�2��������Ϊ�Խǣ����������⣩��ģ�⼴��
const int MAX = 40;
const int START_R = 20;
const int START_C = 20;
int t;
int n;
int dp[MAX][MAX][MAX];//dp[i][j][k] ��ʾ i������ (j, k) �ķ�����
/*dp[i][j][k] = dp[i - 1][j - 1][k - 1] + dp[i - 1][j - 1][k] +
			    dp[i - 1][j][k - 1] + dp[i - 1][j][k + 1] +
				dp[i - 1][j + 1][k] + dp[i - 1][j + 1][k + 1]*/ 
int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	int i, j, k;
	dp[0][START_R][START_C] = 1;
	for (i = 1; i <= 14; i ++) {
		for (j = 1; j < MAX; j ++) {
			for (k = 1; k < MAX; k ++) {
				dp[i][j][k] = dp[i - 1][j - 1][k - 1] + dp[i - 1][j - 1][k] +
							  dp[i - 1][j][k - 1] + dp[i - 1][j][k + 1] +
							  dp[i - 1][j + 1][k] + dp[i - 1][j + 1][k + 1];
			}
		}
	}

	scanf( "%d", &t );
	while (t --) {
		scanf( "%d", &n );
		printf( "%d\n", dp[n][START_R][START_C] );
	}

	return 0;
}
