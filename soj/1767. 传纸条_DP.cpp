#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 60;
int n, m;
int matric[MAX][MAX], dp[3 * MAX][MAX][MAX];
//dp[s][i][j]表示走s步，下表分别为 (i, s+2-i)和(j, s+2-j)
int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
		
	while (scanf( "%d%d", &n, &m ) != EOF) {
		memset(dp, 0, sizeof(dp));
		memset(matric, 0, sizeof(matric));

		int i, j;
		for (i = 1; i <= n; i ++) {
			for (j = 1; j <= m; j ++) {
				scanf( "%d", &matric[i][j] );
			}
		}

		int s, a1, b1, a2, b2;
		for (s = 1; s <= n + m - 3; s ++) {
			for (a1 = 1; a1 <= n; a1 ++) {

				b1 = s + 2 - a1;
				if (b1 < 1 || b1 > m) {
					continue;
				}

				for (a2 = 1; a2 <= n; a2 ++) {
					if (a1 == a2) {
						continue;
					}

					b2 = s + 2 - a2;
					if (b2 < 1 || b2 > m) {
						continue;
					}

					int temp = dp[s - 1][a1][a2];

					int prea1 = a1, prea2 = a2 - 1;
					if (a2 - 1 != a1) {
						temp = max(temp, dp[s - 1][prea1][prea2]);
					}

					prea1 = a1 - 1, prea2 = a2 - 1;
					temp = max(temp, dp[s - 1][prea1][prea2]);
					
					prea1 = a1 - 1, prea2 = a2;
					if (a1 - 1 != a2) {
						temp = max(temp, dp[s - 1][prea1][prea2]);
					}

					dp[s][a1][a2] = temp + matric[a1][b1] + matric[a2][b2];
				}
			}
		}

		printf( "%d\n", dp[n + m - 3][n][n - 1] );
	}

	return 0;
}
