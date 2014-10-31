#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, sum;
int magicSquare[15][15];
bool visited[15][15];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	int flag = 0;
	while (scanf( "%d", &n ) != EOF)
	{
		if (flag ++ > 0)
			printf( "\n" );

		memset(visited, false, sizeof(visited));
		int num = 1, MAX = n*n;
		int preX = 0, preY = n >> 1, nextX, nextY;;
		magicSquare[preX][preY] = num ++;
		visited[preX][preY] = true;
		while (num <= MAX)
		{
			nextX = (preX == 0) ? n-1 : preX-1;
			nextY = (preY == n-1) ? 0 : preY+1;
			if (!visited[nextX][nextY])
				visited[nextX][nextY] = true;
			else
			{
				nextX = (preX == n-1) ? 0 : preX+1;
				nextY = preY;
				visited[nextX][nextY] = true;
			}
			magicSquare[nextX][nextY] = num ++;
			preX = nextX;	preY = nextY;
		}

		sum = 0;
		for (int i = 0; i < n; i ++)
			sum += magicSquare[0][i];

		printf( "n=%d, sum=%d\n", n, sum );
		int a = 5;
		if (n < 4)
			for (int i = 0; i < n; i ++)
			{
				for (int j = 0; j < n; j ++)
					printf( "%2d", magicSquare[i][j] );
				printf( "\n" );
			}
		else if (n < 10)
			for (int i = 0; i < n; i ++)
			{
				for (int j = 0; j < n; j ++)
					printf( "%3d", magicSquare[i][j] );
				printf( "\n" );
			}
		else
			for (int i = 0; i < n; i ++)
			{
				for (int j = 0; j < n; j ++)
					printf( "%4d", magicSquare[i][j] );
				printf( "\n" );
			}
	}

    return 0;
}

