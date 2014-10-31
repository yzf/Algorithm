#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 501;
int cases;
int n, m;
int a[MAX], b[MAX];
int dp[MAX][MAX], dist[MAX][MAX];
//dp[i][j]表示a的前i个数和b的前j个数选i个使得 |a1-b1| + … + |ai –bi|}最小
int abs(int num) 
{
	return num > 0 ? num : -num;
}
int main()  
{  
    //freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &cases );
	while (cases --) {

		scanf( "%d%d", &n, &m );
		for (int i = 1; i <= n; i ++) {
			scanf( "%d", &a[i] );
		}
		for (int i = 1; i <= m; i ++) {
			scanf( "%d", &b[i] );
		}
		
		sort(a+1, a+1+n);
		sort(b+1, b+1+m);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				dist[i][j] = abs(a[i] - b[j]);
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (i == 1) {
				dp[i][i] = dist[i][i];
			}
			else {
				dp[i][i] = dp[i - 1][i - 1] + dist[i][i];
			}
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= m; j ++) {
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + dist[i][j]);
			}
		}

		printf( "%d\n", dp[n][m] );
	}

    return 0;  
} 
