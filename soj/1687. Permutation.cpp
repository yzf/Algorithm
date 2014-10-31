#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 110;
int n, k;
int dp[MAX][MAX];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	for (int i = 1; i <= 100; i ++) {
		for (int j = 0; j < i; j ++) {
            
			if ((!(i & 1) && j >= i/2) || ((i & 1) && j > i/2)) {
				dp[i][j] = dp[i][i - j - 1];
			}
			else if (j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = ((i - j) * dp[i - 1][j - 1] + (j + 1) * dp[i - 1][j]) % 2007;
			}
		}
	}

	while (scanf( "%d%d", &n, &k ) != EOF) {
		printf( "%d\n", dp[n][k] );
	}

    return 0;
}
/*
1     
1     1     
1     4     1     
1     11    11    1     
1     26    66    26    1     
1     57    302   302   57    1     
1     120   1191  409   1191  120   1 

由此推出规律： 
1.dp[i][j] = dp[i][i-j-1] (i % 2 == 0 && j >= i/2 || i % 2 == 1 && j > i/2)
2.dp[i][j] = 1 (j == 0)
3.dp[i][j] = (i - j) * dp[i - 1][j - 1] + (j + 1) * dp[i - 1][j]
*/
