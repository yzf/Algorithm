#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 30001;
int n, k, x, y, got, total, root, root2;//got为每次取得的节点数，total为剩下的节点数，root为当前树的根节点，root2为截成两棵树后的另一个根节点
int father[MAX], minID[MAX], cnt[MAX];//minID[i]为以节点i为根的树的最小下标，cnt[i]为节点个数
bool flag, isCut[MAX];//flag标记是否包括根节点
vector<int> adj[MAX];//保存边

void buildTree(int node,int fa)
{
	father[node] = fa;
	minID[node] = node;
	cnt[node] = 1;
	for (int i = 0; i < adj[node].size(); i ++) {
		int j = adj[node][i];
		if (!isCut[j] && j != fa) {
			buildTree(j, node);
			minID[node] = min(minID[node], minID[j]);
			cnt[node] += cnt[j];
		}
	}
}

void update(int node)
{
	minID[node] = node;
	cnt[node] = 1;
	for (int i = 0; i < adj[node].size(); i ++) {
		int j = adj[node][i];
		if (!isCut[j]) {
			buildTree(j, node);
			minID[node] = min(minID[node], minID[j]);
			cnt[node] += cnt[j];
		}
	}
}

void dfs(int node)
{
	int tcnt = cnt[node];
	int sum = tcnt * 2;
	bool tflag = false;//标记原树的根节点是否在截去部分
	if (sum > total) {//多于一半
		tcnt = total - tcnt;
		tflag = true;
	}
	if (got < tcnt) {//数量更优时更新
		got = tcnt;
		flag = tflag;
		root2 = node;
	}
    else if (got == tcnt) {//数量相同时取更优值
		//实际上，一个包括原树根节点，另一个不包括的情况以及两个都不包括的情况不可能。
		if (minID[node] < minID[root2]) {//虽然对于只剩下一条链时不一定取到序号最小的，但不影响取点个数
			root2 = node;
			flag = tflag;
		}
	}
	for (int i = 0; i < adj[node].size(); i ++) {
		int j = adj[node][i];
		if (!isCut[j])
			dfs(j);
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d%d", &n, &k );
	for (int i = 1; i < n; i ++) {
		scanf( "%d%d", &x, &y );
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	root = 1;	
	buildTree(root, -1);

	for (int i = 2; i <= n; i ++) {
		adj[i].erase(find(adj[i].begin(), adj[i].end(), father[i]));
	}//变成有向图

	total = n;	flag = false;	root2 = 0;
	while (-- k) {
		got = 0;
		dfs(root);
		total -= got;
		printf( "%d ", got );
		if (flag) {//根节点在截去部分时
			root = root2;
			father[root] = -1;
		}
		else {
			isCut[root2] = true;
			update(root);
		}
	}
	printf( "%d\n", total );

    return 0;
}
