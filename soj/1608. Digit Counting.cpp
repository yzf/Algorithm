#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n;
int cn[10];

void countDigit(int number)
{
	while (number > 0)
	{
		cn[number%10] ++;
		number /= 10;
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	while (cases --)
	{
		memset(cn, 0, sizeof(cn));
		scanf( "%d", &n );

		for (int i = 1; i <= n; i ++)
			countDigit(i);

		printf( "%d", cn[0] );
		for (int i = 1; i < 10; i ++)
			printf( " %d", cn[i] );
		printf( "\n" );
	}

    return 0;
}
