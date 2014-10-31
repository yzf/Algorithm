#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, data[3];
int ans[3][6];
char times[15];

void transform()
{
	int i, j;
	for (i = 0; i < 3; i ++)
	{
		j = 0;
		while(data[i] > 0)
		{
			ans[i][j ++] = data[i] % 2;
			data[i] /= 2;
		}
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	for (int i = 1; i <= cases; i ++)
	{
		scanf( "%s", times );
		memset(ans, 0, sizeof(ans));
		data[0] = (times[0]-'0')*10 + (times[1]-'0');
		data[1] = (times[3]-'0')*10 + (times[4]-'0');
		data[2] = (times[6]-'0')*10 + (times[7]-'0');

		transform();

		printf( "%d ", i );
		for (int j = 5; j >= 0; j --)
		{
			for (int k = 0; k < 3; k ++)
				printf( "%d", ans[k][j] );
		}
		printf( " " );
		for (int k = 0; k < 3; k ++)
		{
			for (int j = 5; j >= 0; j --)
				printf( "%d", ans[k][j] );
		}
		printf( "\n" );
	}

    return 0;
}
