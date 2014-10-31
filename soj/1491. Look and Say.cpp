#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases;
char str[1010];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%s", str );
		int len = strlen(str);
		int cn = 1;
		for (int i = 0; i < len; i ++)
		{
			if (str[i] != str[i+1])
			{
				printf( "%d%c", cn, str[i] );
				cn = 1;
			}
			else
				cn ++;
		}
		printf( "\n" );
	}

    return 0;
}
