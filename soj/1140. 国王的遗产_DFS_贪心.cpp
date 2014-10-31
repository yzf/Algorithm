#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 30001;
int n, k, x, y, got, total, root, root2;//gotΪÿ��ȡ�õĽڵ�����totalΪʣ�µĽڵ�����rootΪ��ǰ���ĸ��ڵ㣬root2Ϊ�س������������һ�����ڵ�
int father[MAX], minID[MAX], cnt[MAX];//minID[i]Ϊ�Խڵ�iΪ����������С�±꣬cnt[i]Ϊ�ڵ����
bool flag, isCut[MAX];//flag����Ƿ�������ڵ�
vector<int> adj[MAX];//�����

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
	bool tflag = false;//���ԭ���ĸ��ڵ��Ƿ��ڽ�ȥ����
	if (sum > total) {//����һ��
		tcnt = total - tcnt;
		tflag = true;
	}
	if (got < tcnt) {//��������ʱ����
		got = tcnt;
		flag = tflag;
		root2 = node;
	}
    else if (got == tcnt) {//������ͬʱȡ����ֵ
		//ʵ���ϣ�һ������ԭ�����ڵ㣬��һ��������������Լ�����������������������ܡ�
		if (minID[node] < minID[root2]) {//��Ȼ����ֻʣ��һ����ʱ��һ��ȡ�������С�ģ�����Ӱ��ȡ�����
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
	}//�������ͼ

	total = n;	flag = false;	root2 = 0;
	while (-- k) {
		got = 0;
		dfs(root);
		total -= got;
		printf( "%d ", got );
		if (flag) {//���ڵ��ڽ�ȥ����ʱ
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
