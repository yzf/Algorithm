#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 21;
const int oo = 100000;
int cases, m, n, c, id;
int st, ed;
char flag[10];
int maxFlow, pre[MAX], curFlow[MAX], cap[MAX][MAX], flow[MAX][MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    scanf( "%d", &cases );
    while (cases --) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        scanf( "%d%d", &m, &n );
        st = MAX - 1;
        ed = n;
        for (int i = 0; i < m; i ++) {
            scanf( "%s%d", flag, &c );
            for (int j = 0; j < c; j ++) {
                scanf( "%d", &id );
                if (i != ed) {
                    cap[i][id] = oo;
                }
                if (id != ed) {
                    cap[id][i] ++;//两个房间之间可以多于1个门。。WA N次。。
                }
            }
            if (flag[0] == 'I') {
                cap[st][i] = oo;
            }
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
                for (int v = 0; v < m; v ++) {
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
            for (int v = ed; v != st; v = pre[v]) {
                flow[ pre[v] ][v] += curFlow[ed];
                flow[v][ pre[v] ] -= curFlow[ed];
            }
            maxFlow += curFlow[ed];
        }
        if (maxFlow >= oo) {
            printf( "PANIC ROOM BREACH\n" );
        }
        else {
            printf( "%d\n", maxFlow );
        }
    }

    return 0;
}
