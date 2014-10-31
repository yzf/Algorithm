#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 110;
int n;
int data[MAX];
bool flag[MAX];
int ans, dp[MAX][MAX];
//dp[i][j] �б� i ��ʾ�� i ���㣬�б� j ��ʾ���ڵ� i ����ĵ����Ŀ
int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &n ) && n) {

		for (int i = 0; i < n; i ++) {
			scanf( "%d", &data[i] );
		}
		for (int i = 1; i < n; i ++) {
			flag[i] = data[i] > data[i - 1] ? true : false;
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i < n; i ++) {
			for (int j = 0; j <= i; j ++) {
				//�����������ô dp[i - 1][j] ��Ӧ��λ�ö��ܹ����� dp[i][j+1..i] ��Ӧ��ĳ��λ�á�
				if (flag[i]) {
					for (int k = j + 1; k <= i; k ++) {
						dp[i][k] += dp[i - 1][j];
					}
				}
				//����½�����ô dp[i - 1][j] ��Ӧ��λ�ö��ܹ����� dp[i][0..j] ��Ӧ��ĳ��λ�á�
				else {
					for (int k = 0; k <= j; k ++) {
						dp[i][k] += dp[i - 1][j];
					}
				}
			}
		}

		ans = 0;
		for (int i = 0; i < n; i ++) {
			ans += dp[n - 1][i];
		}
		printf( "%d\n", ans );
	}

    return 0;
}

