#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10;

int m, n, sum;
int matrix[MAX][MAX];

void dfs(int s, int x, int y)
{
	if (x == m-1 && y == n-1)
		if (sum < 0 || (s > 0 && s < sum))
		{
			sum = s;
			return ;
		}

	if (x+1 < m)
		dfs(s+matrix[x+1][y], x+1, y);
	if (y+1 < n)
		dfs(s+matrix[x][y+1], x, y+1);
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &m, &n ) != EOF)
	{
		for (int i = 0; i < m; i ++)
			for (int j = 0; j < n; j ++)
				scanf( "%d", &matrix[i][j] );

		sum = -10000000;
		dfs(matrix[0][0], 0, 0);

		if (sum <= 0)
			printf( "-1\n" );
		else
			printf( "%d\n", sum );
	}
  
    return 0;
}
