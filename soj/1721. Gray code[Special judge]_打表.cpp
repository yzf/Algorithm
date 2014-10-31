#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1 << 16;
int n;
bool gray[MAX+1][16];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	memset(gray, false, sizeof(gray));
	
	for (int j = 15; j >= 0; j --)
	{
		int cn1 = 0;
		int cn2 = 1 << (16-j);
		for (int i = (1 << (16-j-1)); i < MAX; i ++, cn1 ++)
		{
			if (cn1 == cn2)
			{
				cn1 = 0;
				i += cn2;
			}
			if (i >= MAX)
				break;
			gray[i][j] = true;
		}
	}

	while (scanf( "%d", &n ) && n != 0)
	{
		for (int i = 0; i < (1 << n); i ++)
		{
			for (int j = 16-n; j < 16; j ++)
				printf( "%d", gray[i][j] );
			printf( "\n" );
		}
		printf( "\n" );
	}
    
	return 0;    
}
