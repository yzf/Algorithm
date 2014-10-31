#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m, a, b;
bool edge[210][210];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	for (scanf( "%d", &n ); n != 0; scanf( "%d", &n ))
	{
		int no;

		scanf( "%d", &m );
		memset(edge, false, sizeof(edge));
		
		for (int i = 0; i < m; i ++)
		{
            scanf( "%d%d", &a, &b );
            edge[a][b] = true;
        }

		for (int k = 0; k < n; k ++)//warshallËã·¨
			for (int i = 0; i < n; i ++)
				for (int j = 0; j < n; j++)
					edge[i][j] = edge[i][j] || (edge[i][k] && edge[k][j]);

		if (edge[0][n-1])
			printf( "I can post the letter\n" );
		else
			printf( "I can't post the letter\n" );
	}

	return 0;
}
