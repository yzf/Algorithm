#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 210;
int n, m, dp[MAX][MAX];
struct Data {
	int a, b;
	bool operator < (const Data rhs) const {
		return b > rhs.b;
	}
} data[MAX];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	memset(dp, 0, sizeof(dp));
	scanf( "%d%d", &n, &m );
	for (int i = 1; i <= n; i ++) {
		scanf( "%d", &data[i].a );
	}
	for (int i = 1; i <= n; i ++) {
		scanf( "%d", &data[i].b );
	}
	sort(data+1, data+1+n);
	for (int k = 1; k <= m; k ++){
		for (int i = 1; i <= n; i ++) {
			dp[i][k] = max(dp[i-1][k], dp[i-1][k-1] + data[i].a - (k - 1) * data[i].b);
		}
	}

	printf( "%d\n", dp[n][m] );

    return 0;
}
