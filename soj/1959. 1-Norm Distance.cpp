#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a1, b1, a2, b2;

int abs(int &x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	scanf( "%d%d%d%d", &a1, &b1, &a2, &b2 );
	printf( "%d\n", abs(a1-a2)+abs(b1-b2) );
    
    return 0;
}
