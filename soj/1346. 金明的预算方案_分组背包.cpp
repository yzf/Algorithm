#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
//分组背包问题
const int MAX = 60;
int n, m;
int v, p, q;
int cn;
bool isAcc[MAX];
struct A {
	int value;
	int cost;
	A(int tv = 0, int tc = 0) : value(tv), cost(tc) {}
} a[MAX];
int ans;
vector<A> aa[MAX];
int f[32010];

int main()  
{  
    //freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	while (scanf( "%d%d", &n, &m ) != EOF) {

		memset(isAcc, false, sizeof(isAcc));
		vector<A> md[MAX];
		for (int i = 1; i <= m; i ++) {
			scanf( "%d%d%d", &v, &p, &q );
			if (q != 0) {
				isAcc[i] = true;
				md[q].push_back(A(v*p, v));
			}
			else {
				a[i] = A(v*p, v);
			}
		}

		for (int i = 0; i <= 2*m; i ++) {
			aa[i].clear();
		}
		cn = 0;
		for (int i = 1; i <= m; i ++) {
			if (!isAcc[i]) {
				aa[cn].push_back(a[i]);
				for (int j = 0; j < md[i].size(); j ++) {
					aa[cn].push_back(A(a[i].value + md[i][j].value, a[i].cost + md[i][j].cost));
				}
				if (md[i].size() == 2) {
					aa[cn].push_back(A(a[i].value + md[i][0].value + md[i][1].value, a[i].cost + md[i][0].cost + md[i][1].cost));
				}
				cn ++;
			}
		}

		ans = 0;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < cn; i ++) {
			for (int j = n; j >= 0; j --) {
				for (int k = 0; k < aa[i].size(); k ++) {
					if (j >= aa[i][k].cost) {
						f[j] = max(f[j], f[j - aa[i][k].cost] + aa[i][k].value);
						ans = max(ans, f[j]);
					}
				}
			}
		}

		printf( "%d\n", ans );
	}

    return 0;  
} 
