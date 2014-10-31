#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
//分组背包问题，奇怪的是用一维WA，二维才AC。。。 
int t, p, n;
int d, e, m;
int i, j, k;
int dp[110][1100], ans;
struct Sport {
	int e, m;
	Sport(int te = 0, int tm = 0) : e(te), m(tm) {}
} cur;
vector<Sport> day[110];

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &t );
	while (t --) {

		scanf( "%d%d", &p, &n );
		for (i = 0; i < 110; i ++) {
			day[i].clear();
		}

		while (n --) {
			scanf( "%d%d%d", &d, &e, &m );
			d ++;
			day[d].push_back(Sport(e, m));
		}

		memset(dp, 0, sizeof(dp));
		ans = 0;
		for (k = 1; k <= d; k ++) {
			for (j = p; j >= 0; j --) {
				dp[k][j] = dp[k - 1][j];
				for (i = 0; i < day[k].size(); i ++) {
					cur = day[k][i];
					if (j >= cur.e) {
						dp[k][j] = max(dp[k][j], dp[k - 1][j - cur.e] + cur.m);
					}
				}
				ans = max(ans, dp[k][j]);
			}
		}

		printf( "%d\n", ans );
	}

    return 0;  
} 
