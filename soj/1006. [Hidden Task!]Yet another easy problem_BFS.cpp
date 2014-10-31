#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int t, n, a, b;
int ans[510];
bool flag[510];
struct Node {
	int id, level;
	Node(int tid = -1, int tl = -1) : id(tid), level(tl) {}
} node;

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &t );
	while (t --) {
		vector<int> adj[510];
		queue<Node> que;
		scanf( "%d", &n );
		memset(flag, false, n*sizeof(bool));
		for (int i = 1; i < n; i ++) {
			scanf( "%d%d", &a, &b );
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		que.push(Node(0, 0));
		flag[0] = true;
		while (!que.empty()) {
			node = que.front();
			que.pop();
			ans[node.id] = node.level;
			for (int i = 0; i < adj[node.id].size(); i ++) {
				int j = adj[node.id][i];
				if (!flag[j]) {
					flag[j] = true;
					que.push(Node(j, node.level + 1));
				}
			}
		}
		for (int i = 0; i < n; i ++) {
			printf( "%d\n", ans[i] );
		}
	}

    return 0;  
} 
