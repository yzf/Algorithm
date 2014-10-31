#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 110;
const int oo = 10000000;
int cases, n, m, a, b, st, ed;
int maxFlow, pre[MAX], curFlow[MAX], cap[MAX][MAX], flow[MAX][MAX];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --) {
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		scanf( "%d%d", &n, &m );
		for (int i = 1; i < n; i ++) {
			scanf( "%d", &cap[i][i + n] );//²ðµã
		}
		while (m --) {
			scanf( "%d%d", &a, &b );
			if (a != 0 && b != 0 && a != n && b != n) {
				cap[a + n][b] = cap[b + n][a] = oo;
			}
			if (a == 0) {
				cap[a][b] = oo;
			}
			if (b == 0) {
				cap[b][a] = oo;
			}
			if (a == n) {
				cap[b + n][a] = oo;
			}
			if (b == n) {
				cap[a + n][b] = oo;
			}
		}

		st = maxFlow = 0;
		ed = n;
		while (true) {//Edmonds-Karp  
			memset(curFlow, 0, sizeof(curFlow));
			queue<int> que;
			que.push(st);
			curFlow[st] = oo;
			while (!que.empty()) {
				int u = que.front();
				que.pop();
				for (int v = 0; v < 2 * n; v ++) {
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
			for (int u = n; u != st; u = pre[u]) {
				flow[ pre[u] ][u] += curFlow[ed];
				flow[u][ pre[u] ] -= curFlow[ed];
			}
			maxFlow += curFlow[ed];
		}
		printf( "%d\n", maxFlow );
	}

    return 0;
}
