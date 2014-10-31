#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n, state[200];
int times;
char problem[2], result[10];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		memset(state, -1, sizeof(state));
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d%s%s", &times, problem, result );
			if (result[0] == 'A')
				state[ problem[0] ] = 1;
			else if (state[ problem[0] ] == -1)
				state[ problem[0] ] = 0;
		}
		printf( "Accept: " );
		for (int i = 'A'; i <= 'J';  i++)
			if (state[i] == 1)
				printf( "%c", i );
		printf( "\nWrong: " );
		for (int i = 'A'; i <= 'J';  i++)
			if (state[i] == 0)
				printf( "%c", i );
		printf( "\n\n" );
	}

    return 0;
}
