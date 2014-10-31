#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a, b, sum;

int combination(int n, int s)
{
	int com = 1;
	for (int i = s, j = 1; i >= s-n+1; i --, j ++)
		com = com * i / j;
	return com;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &a, &b ) != EOF)
	{
		if (a == -1 && b == -1)
			break;
		sum = a + b;
		int cb = combination(a, sum);
		if (cb == sum)
			printf( "%d+%d=%d\n", a, b, sum );
		else
			printf( "%d+%d!=%d\n", a, b, sum );
	}

    return 0;
}
