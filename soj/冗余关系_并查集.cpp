#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAX = 1001; 
int n, m, answer, a, b;
int father[MAX], cn[MAX];

void make_set()
{
	for (int i = 1; i <= m; i ++)
	{
		father[i] = i;
		cn[i] = 1;
	}
}

int find_set(int x)
{
	if (x != father[x])
		father[x] = find_set(father[x]);
	return father[x];
}

void union_set(int x, int y)
{
	int fx = find_set(x);
	int fy = find_set(y);
	if (fx == fy)
	{
		answer ++;
	}
	else
	{
		if (cn[fx] > cn[fy])
		{
			father[fy] = fx;
			cn[fx] += cn[fy];
		} else 
		{
			father[fx] = fy;
			cn[fy] += cn[fx];
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d%d", &n, &m );
	make_set();
	answer = 0;
	while (n --)
	{
		scanf( "%d%d", &a, &b );
		union_set(a, b);
	}
	printf( "%d\n", answer );
 
	return 0;
}

