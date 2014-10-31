#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 110;
int n, m, r;
int rmb[MAX], rp[MAX], time[MAX];
int f1[MAX][MAX], f2[MAX][MAX];//f1为gf数，f2为时间
int gfMax, timeMin;
bool visited[MAX][MAX];

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> rmb[i] >> rp[i] >> time[i];
	}
	cin >> m >> r;
	
	visited[0][0] = true;
	for (int i = 0; i <= m; i ++) {
		for (int j = 0; j <= r; j ++) {
			f2[i][j] = 10000000;
		}
	}
	f2[0][0] = 0;
	gfMax = 0;
	timeMin = 10000000;
	for (int i = 0; i < n; i ++) {
		for (int j = m; j - rmb[i] >= 0; j --) {
			int a = j - rmb[i];
			for (int k = r; k - rp[i] >= 0; k --) {
				int b = k - rp[i];
				if (visited[a][b]) {
					if (f1[j][k] < f1[a][b] + 1) {
						f1[j][k] = f1[a][b] + 1;
						f2[j][k] = f2[a][b] + time[i];
					}
					else if (f1[j][k] == f1[a][b] + 1) {
						f2[j][k] = min(f2[j][k], f2[a][b] + time[i]);
					}
					visited[j][k] = true;
					gfMax = max(gfMax, f1[j][k]);
				}
			}
		}
	}
	for (int i = 0; i <= m; i ++) {
		for (int j = 0; j <= r; j ++) {
			if (f1[i][j] == gfMax) {
				timeMin = min(timeMin, f2[i][j]);
			}
		}
	}
	cout << timeMin << endl;

    return 0;
}                                 