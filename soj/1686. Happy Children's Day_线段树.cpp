#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100010;
int n, m, id, candy;
int a, b, c;
char cmd;

struct Segment {
	int l, r, maxid, maxcandy, add;
} tree[4 * MAX];

void createTree(int node, int l, int r)
{
	tree[node].l = tree[node].maxid = l;
	tree[node].r = r;
	tree[node].maxcandy = tree[node].add = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	createTree(2*node, l, mid);
	createTree(2*node+1, mid+1, r);
}

void inherit(int node) 
{
	tree[2*node].maxcandy += tree[node].add;
	tree[2*node].add += tree[node].add;
	tree[2*node+1].maxcandy += tree[node].add;
	tree[2*node+1].add += tree[node].add;
	tree[node].add = 0;
}

void update(int node)
{
	if (tree[2*node].maxcandy >= tree[2*node+1].maxcandy) {
		tree[node].maxid = tree[2*node].maxid;
		tree[node].maxcandy = tree[2*node].maxcandy;
	}
	else {
		tree[node].maxid = tree[2*node+1].maxid;
		tree[node].maxcandy = tree[2*node+1].maxcandy;
	}
}

void insert(int node, int l, int r, int data)
{
	if (tree[node].l == l && tree[node].r == r) {
		tree[node].maxcandy += data;
		tree[node].add += data;
		return ;
	}
	inherit(node);
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (r <= mid) {
		insert(2*node, l, r, data);
	}
	else if (l > mid) {
		insert(2*node+1, l, r, data);
	} 
	else {
		insert(2*node, l, mid, data);
		insert(2*node+1, mid+1, r, data);
	}
	update(node);
}

void search(int node, int l, int r)
{
	if (tree[node].l == l && tree[node].r == r) {
		if (candy == tree[node].maxcandy) {
			id = min(id, tree[node].maxid);
		}
		else if (candy < tree[node].maxcandy) {
			candy = tree[node].maxcandy;
			id = tree[node].maxid;
		}
		return ;
	}
	inherit(node);
	int mid = (tree[node].l + tree[node].r) >> 1;
	if (r <= mid) {
		search(2*node, l, r);
	}
	else if (l > mid) {
		search(2*node+1, l, r);
	}
	else {
		search(2*node, l, mid);
		search(2*node+1, mid+1, r);
	}
	update(node);

}

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	while (scanf( "%d%d", &n, &m ) && n && m) {
		createTree(1, 1, n);
		while (m --) {
			scanf( "%s", &cmd );
			if (cmd == 'I') {
				scanf( "%d%d%d", &a, &b, &c );
				insert(1, a, b, c);
			}
			else {
				scanf( "%d%d", &a, &b );
				id = n;
				candy = 0;
				search(1, a, b);
				printf( "%d\n", candy );
				if (candy != 0) {
					insert(1, id, id, -candy);
				}
			}
		}
	}

    return 0;  
} 
