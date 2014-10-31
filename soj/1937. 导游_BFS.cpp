#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 110;
int cases, n, r;
int a, b, dis;
int s, d, t;
int maxPeo, ans;
int dist[MAX][MAX];
int minPeo[MAX];
bool isVisited[MAX];
struct City {
	int id;
	int peo;
	City() {}
	City(int tid, int tmin) : id(tid), peo(tmin) {}
} ;

void bfs() 
{
	memset(isVisited, false, sizeof(isVisited));
	int temp;
	queue<City > que;
	City cur(s, 100000);
	que.push(cur);
	isVisited[s] = true;
	
	while (!que.empty()) {
		cur = que.front();
		que.pop();

		for (int i = 1; i <= n; i ++) {
			if (dist[cur.id][i] == 0) {
				continue;
			}
			temp = min(dist[cur.id][i], minPeo[cur.id]);
			//和一般的BFS不同，改变了入队的条件，允许有更优值的点重复入队
			if (i != s && (!isVisited[i] || temp > minPeo[i])) {
				isVisited[i] = true;
				minPeo[i] = temp;
				if (i == d) {
					maxPeo = max(maxPeo, temp);
					continue;
				}
				que.push(City(i, temp));
			}
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	while (cases --) {

		scanf( "%d%d", &n, &r );
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= n; i ++) {
			minPeo[i] = 1000000;
		}
		while (r --) {
			scanf( "%d%d%d", &a, &b, &dis );
			dist[a][b] = dist[b][a] = dis;
		}
		scanf( "%d%d%d", &s, &d, &t );

		bfs();

		maxPeo --;
		ans = ceil((double)t / (double)maxPeo);
		printf( "%d\n", ans );
	}

    return 0;
}
