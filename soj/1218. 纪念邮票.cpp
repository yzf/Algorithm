#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d%d", &n, &m );
	int limit = (int)sqrt(2.0*m);
	
	for (int i = limit; i >= 0; i --)
	{
		int temp1 = 2*m % (i+1),
			temp2 = (2*m / (i+1) - i) % 2,
			be = (2*m / (i+1) - i) / 2;//be为第一个数字 
			
		if (be > n || be+i > n)
            continue; 
            
		if (temp1 == 0 && temp2 == 0 && be >= 1)
			printf( "[%d,%d]\n", be, be+i );
	}

    return 0;
}
