#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 500001;
int cases, n, m, order, x, y;
int pre[MAX], ne[MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d%d", &n, &m );
		for (int i = 0; i <= n; i ++)
		{
			pre[i] = i-1;
			ne[i] = i+1;
		}

		while (m --)
		{
			scanf( "%d%d%d", &order, &x, &y);

			ne[ pre[x] ] = ne[x];
			pre[ ne[x] ] = pre[x];
			if (order == 1)
			{
				pre[x] = pre[y];
				ne[x] = y;
				pre[y] = ne[ pre[y] ] = x;
			}
			else
			{
				pre[x] = y;
				ne[x] = ne[y];
				ne[y] = pre[ ne[y] ] = x;
			}
		}

		int index = 0;
		while (ne[index] != n+1)
		{
			printf( "%d ", ne[index] );
			index = ne[index];
		}
		printf( "\n" );
	}

    return 0;
}

