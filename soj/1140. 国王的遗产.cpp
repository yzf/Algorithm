#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 30010;
int n, k, x, y;
int cn[MAX], minID[MAX];
int root, troot, num, total;
bool flag, tflag, isCut[MAX];
vector<int > adj[MAX], son[MAX];

void buildTree(int node, int fa)
{
	cn[node] = 1;
	minID[node] = node;
	int i, j;
	for (i = 0; i < adj[node].size(); i ++) {
		j = adj[node][i];
		if (j != fa) {
			son[node].push_back(j);
			buildTree(j, node);
			cn[node] += cn[j];
			minID[node] = min(minID[node], minID[j]);
		}
	}
}

void update(int node)
{
	cn[node] = 1;
	minID[node] = node;
	int i, j;
	for (i = 0; i < son[node].size(); i ++) {
		j = son[node][i];
		if (!isCut[j]) {
			update(j);
			cn[node] += cn[j];
			minID[node] = min(minID[node], minID[j]);
		}
	}
}

void dfs(int node)
{
	bool tflag = true;
	int tcn = cn[node];
	if (tcn * 2 > total) {
		tflag = false;
		tcn = total - tcn;
	}
	if (tcn > num) {
		num = tcn;
		flag = tflag;
		troot = node;
	}
	else if (tcn == num) {
		if (minID[node] < minID[troot]) {
			troot = node;
			flag = tflag;
		}
	}
	int i, j;
	for (i = 0; i < son[node].size(); i ++) {
		j = son[node][i];
		if (!isCut[j]) {
			dfs(j);
		}
	}
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d%d", &n, &k ) != EOF) {
		
		int i, j;
		for (i = 1; i <= n; i ++) {
			adj[i].clear();
			son[i].clear();
		}
		for (i = 1; i < n; i ++) {
			scanf( "%d%d", &x, &y );
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		root = 1;
		buildTree(root, 0);
		
		memset(isCut, false, sizeof(isCut));
		total = n;
		for (i = 1; i < k; i ++) {
			troot = root;
			flag = tflag = true;
			num = 0;
			dfs(root);
			if (flag) {
				isCut[troot] = true;
			}
			else {
				root = troot;
			}
			printf( "%d ", num );
			total -= num;
			update(root);
		}
		printf( "%d\n", total );
	}
	
	return 0;
}
