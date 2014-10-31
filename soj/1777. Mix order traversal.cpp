#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n, m, lson, rson;
struct Node {
	int left;
	int right;
} node[110];

void print(int root)
{
	if (root < node[root].left)
	{
		printf( "%d ", root );
		if (node[root].left != -1)	print(node[root].left);
		if (node[root].right != -1)	print(node[root].right);
	}
	else if (root < node[root].right)
	{
		if (node[root].left != -1)	print(node[root].left);
		printf( "%d ", root );
		if (node[root].right != -1) print(node[root].right);
	}
	else
	{
		if (node[root].left != -1)	print(node[root].left);
		if (node[root].right != -1) print(node[root].right);
		printf( "%d ", root );
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d%d", &n, &m );
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d%d", &lson, &rson );
			node[i].left = lson;
			node[i].right = rson;
		}
		print(m);
		printf( "\n" );
	}

	return 0;
}
