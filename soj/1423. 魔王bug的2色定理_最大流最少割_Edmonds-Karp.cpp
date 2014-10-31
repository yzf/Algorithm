#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 210;
const int oo = 10000000;
int n, m, x, y, st, ed;
int h, b, num;
int maxFlow, pre[MAX], curFlow[MAX], cap[MAX][MAX], flow[MAX][MAX];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &n, &m ) != EOF) {
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		st = 0;
		ed = n + 1;

		while (m --) {
			scanf( "%d%d", &x, &y );
			cap[x][y] = 1;
			cap[y][x] = 1;
		}

		scanf( "%d", &h );
		while (h --) {//将已染黑色的都看成源 
			scanf( "%d", &num );
			cap[st][num] = oo;
		}
		scanf( "%d", &b );
		while (b --) {//将已染白色的都看成汇 
			scanf( "%d", &num );
			cap[num][ed] = oo;
		}

		maxFlow = 0;
		while (true) {
			memset(curFlow, 0, sizeof(curFlow));
			queue<int> que;
			que.push(st);
			curFlow[st] = oo;
			while (!que.empty()) {
				int u = que.front();
				que.pop();
				for (int v = 1; v <= n+1; v ++) {
					if (!curFlow[v] && cap[u][v] > flow[u][v]) {
						pre[v] = u;
						que.push(v);
						curFlow[v] = min(curFlow[u], cap[u][v] - flow[u][v]);
					}
				}
			}
			if (curFlow[ed] == 0) {
				break;
			}
			for (int u = ed; u != st; u = pre[u]) {
				flow[ pre[u] ][u] += curFlow[ed];
				flow[u][ pre[u] ] -= curFlow[ed];
			}
			maxFlow += curFlow[ed];
		}
		
		printf( "%d\n", maxFlow );
	}

    return 0;
}
