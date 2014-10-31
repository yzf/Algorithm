#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 110;
int n;
int data[MAX];
bool flag[MAX];
int ans, dp[MAX][MAX];
//dp[i][j] 行标 i 表示第 i 个点，列标 j 表示低于第 i 个点的点的数目
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
				//如果上升，那么 dp[i - 1][j] 对应的位置都能够产生 dp[i][j+1..i] 对应的某个位置。
				if (flag[i]) {
					for (int k = j + 1; k <= i; k ++) {
						dp[i][k] += dp[i - 1][j];
					}
				}
				//如果下降，那么 dp[i - 1][j] 对应的位置都能够产生 dp[i][0..j] 对应的某个位置。
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

