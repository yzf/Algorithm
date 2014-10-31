#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
/*
这题是求完全图中不同树的数目k，另外还要乘上一个全排列(n-1)!, 因为有n-1条边。
k = n^(n-2)
result = k * (n-1)!
*/
const int nn = 10007;
int n, result;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	result = 1;
	for (int i = 1; i <= n-2; i ++)
	{
		result *= n;
		result %= nn;
	}
	for (int i = 1; i <= n-1; i ++)
	{
		result *= i;
		result %= nn;
	}

	printf( "%d\n", result );

    return 0;
}
