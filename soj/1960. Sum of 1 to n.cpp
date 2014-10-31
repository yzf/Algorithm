#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long cases, n;

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	scanf( "%lld", &cases );
	while (cases --)
	{
		scanf( "%lld", &n );
		printf( "%lld\n", n*(n+1)/2 );
	}
    
    return 0;
}
