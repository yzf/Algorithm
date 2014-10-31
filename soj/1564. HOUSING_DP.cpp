#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int dp[110][110]; 
int ans[110];
/*
dp[i][j] = 1    ( i == j ),     
dp[i][j] = dp[i][j] + dp[i - j][k]    
( 5 <= j <= i / 2, j <= k <= i - j ) 
*/
int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	int i, j, k;
	for (i = 5; i <= 100; i ++) {
		dp[i][i] = 1;
		for (j = 5; j <= i / 2; j ++) {
			for (k = j; k <= i - j; k ++) {
				dp[i][j] += dp[i - j][k];
			}
		}
	}
	
	for (i = 5; i <= 100; i ++) {
		for (j = 5; j <= i; j ++) {
			ans[i] += dp[i][j];
		}
	}

	while (cin >> n) {
		cout << ans[n] << endl;
	}

	return 0;
}
