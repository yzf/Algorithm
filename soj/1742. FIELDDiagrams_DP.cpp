#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
/*
��f[k][i][j]��ʾ fieldOrder Ϊ k������Ϊ i������ j ��β�� FIELD diagrams ����
       f [k][i][j] = f[k][i][j] + f[k][i - 1][t]    
	   ( 1 <= j <= k - i + 1, j <= t <= k )
*/
const int MAX = 31;
int field;
long long dp[MAX][MAX][MAX], ans[MAX];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	int i, j, k, t;
	for (k = 1; k <= 30; k ++) {
		for (i = 1; i <= k; i ++) {
			for (j = 1; j <= k - i + 1; j ++) {
				if (i == 1) {
					dp[k][i][j] = 1;
					continue;
				}
				for (t = j; t <= k; t ++) {
					dp[k][i][j] += dp[k][i - 1][t];
				}
			}
		}
	}

	for (k = 1; k <= 30; k ++) {
		for (i = 1; i <= k; i ++) {
			for (j = 1; j <= k; j ++) {
				ans[k] += dp[k][i][j];
			}
		}
	}

	while (cin >> field) {
		cout << ans[field] << endl;
	}

	return 0;
}
