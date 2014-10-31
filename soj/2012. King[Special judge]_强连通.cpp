#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
//自己第一次写强连通，写得有点烂
const int MAX = 1010;
int n;
int mark[MAX], cn1;
int cn2;
char str[MAX];
bool visit[MAX], flag[MAX];
vector<int> adj[MAX], radj[MAX];

void dfs1(int id)
{
	visit[id] = true;
	int i, j;
	for (i = 0; i < adj[id].size(); i ++) {
		j = adj[id][i];
		if (!visit[j]) {
			dfs1(j);
		}
	}
	mark[++ cn1] = id;
}

void dfs2(int id)
{
	visit[id] = false;
	int i, j;
	for (i = 0; i < adj[id].size(); i ++) {
		j = adj[id][i];
		flag[j] = false;
	}
	for (i = 0; i < radj[id].size(); i ++) {
		j = radj[id][i];
		if (visit[j]) {
			dfs2(j);
		}
	}
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &n ) != EOF) {
		int i, j;
		for (i = 1; i <= n; i ++) {
			adj[i].clear();
			radj[i].clear();
		}
		for (i = 1; i <= n; i ++) {
			scanf( "%s", str );
			for (j = 1; j <= n; j ++) {
				if (str[j - 1] == '1') {
					adj[i].push_back(j);
					radj[j].push_back(i);
				}
			}
		}

		memset(visit, false, sizeof(visit));
		cn1 = 0;
		for (i = 1; i <= n; i ++) {
			if (!visit[i]) {
				dfs1(i);
			}
		}
		memset(flag, true, sizeof(flag));
		cn2 = 0;
		for (i = n; i > 0; i --) {
			j = mark[i];
			if (visit[j]) {
				bool temp = flag[j];
				cn2 ++;
				dfs2(j);
				flag[j] = temp;
			}
		} 
		if (cn2 == 1) {
			printf( "1\n" );
		}
		else {
			int cn = 0;
			int ans = 0;
			for(i = 1; i <= n; i ++) {
				if (flag[i]) {
					cn ++;
					ans = i;
				}
			}
			if (cn == 1) {
				printf( "%d\n", ans );
			}
			else {
				printf( "-1\n" );
			}
		}
	}
	
	return 0;
}
