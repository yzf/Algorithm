#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 110;
int n, k, a, b, apple[MAX], temp1[2*MAX], temp2[2*MAX], back[MAX][2*MAX], notBack[MAX][2*MAX];
//back[i][j]表示i点走j步且回到i点的最优值，notBack则不必回
vector<int> adj[MAX];

void dp(int curNode, int addNode)
{
	memset(temp1, 0, sizeof(temp1));
	memset(temp2, 0, sizeof(temp2));
	for (int step = 0; step <= k; step ++) {//notBack[x][i] = max( back[x][j]+notBack[y][i-j], back[y][j]+notBack[x][i-j] ), j=0.....i
		for (int i = 0; i <= step; i ++) {
			temp1[step] = max(temp1[step], max(back[curNode][i]+notBack[addNode][step-i], back[addNode][i]+notBack[curNode][step-i]));
		}
	}
	for (int step = 0; step <= k; step ++) {//back[x][i] = max( back[x][j]+back[y][i-j] ) j=0,.....i;
		for (int i = 0; i <= step; i ++) {
			temp2[step] = max(temp2[step], back[curNode][i]+back[addNode][step-i]);
		}
	}

	for (int step = 0; step <= k; step ++) {//update
		notBack[curNode][step] = temp1[step];
		back[curNode][step] = temp2[step];
	}
}
//dfs实现树形DP
void dfs(int curNode, int father)
{
	for (int i = 0; i < adj[curNode].size(); i ++) {
		int child = adj[curNode][i];
		if (child != father) {
			dfs(child, curNode);
			for (int step = k; step >= 2; step --) {
				back[child][step] = back[child][step - 2] + apple[child];
			}
			
			for (int step = k; step >= 1; step --) {
				notBack[child][step] = notBack[child][step - 1] + apple[child];
			}
			dp(curNode, child);
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &n, &k ) != EOF) {
		memset(back, 0, sizeof(back));
		memset(notBack, 0, sizeof(notBack));
		for (int i = 1; i <= n; i ++) {
			scanf( "%d", &apple[i] );
			adj[i].clear();
		}
		for (int i = 1; i < n; i ++) {
			scanf( "%d%d", &a, &b );
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1, 1);//把节点1的father设成1 
		printf( "%d\n", notBack[1][k] + apple[1] );
	}

    return 0;
}
