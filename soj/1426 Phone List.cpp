#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10000;

struct Tree {
	bool flag;
	Tree *node[10];
	Tree() : flag(false)
	{
		for (int i = 0; i < 10; i ++)
			node[i] = NULL;
	}
} *root;

struct PhoneNumber {
	char str[15];
	int len;
} phone[MAX];

int t, n;
bool mark;

bool cmp(const PhoneNumber &, const PhoneNumber &);
void visit(Tree *p, char *s);
void release(Tree *);


int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --)
	{
		root = new Tree;
		root->flag = true;
		mark = true;

		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
		{
			scanf( "%s", phone[i].str );
			phone[i].len = strlen(phone[i].str);
		}

		sort(phone, phone+n, cmp);

		for (int i = 0; i < n; i ++)
		{
			if (!mark)
				break;
			visit(root, phone[i].str);
		}

		if (mark)
			printf( "YES\n" );
		else
			printf( "NO\n" );

		release(root);
	}

    return 0;
}

bool cmp(const PhoneNumber &a, const PhoneNumber &b)
{
	return (a.len > b.len);
}

void visit(Tree *p, char *s)
{
	int index = s[0] - '0';

	if (!(p->node[index]))
	{
		p->node[index] = new Tree;
	}
	p = p->node[index];
	
	if (s[1])
	{
		visit(p, s+1);
		p->flag = true;
	}
	else
	{
		if (p->flag == true)
			mark = false;
	}
}

void release(Tree *root)
{
	for (int i = 0; i < 10; i ++)
		if (root->node[i])
			release(root->node[i]);
	delete root;
}
