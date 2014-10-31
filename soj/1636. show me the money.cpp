#include <iostream>
#include <cstdio>

using namespace std;

int t;
int m, n;
int a, b;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --)
	{
		int sum = 0;
	    scanf( "%d%d", &m, &n );
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d%d", &a, &b );
			sum += a * b;
		}
		if (m - sum >= 0)
			printf( "%d\n", m-sum );
		else
			printf( "Not enough\n" );
	}
	
	return 0;
}
