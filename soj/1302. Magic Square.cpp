#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000000;
int n, increase;
long long f[MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	increase = 7;
	f[1] = 1;	f[3] = 2;
	for (int i = 5; i < MAX; i += 2)
	{
		f[i] = f[i-2] + increase;
		increase += 4;
	}

    while (scanf( "%d", &n ) && n != 0)
		printf( "%lld\n", f[n] );

    return 0;
}
/*
想了很久，最后写出来，发现真的有规律
f(1) = 1
+1
f(3) = 2 
+7
f(5) = 9 
+11 = 7 + 4
f(7) = 20
+15 = 11 + 4
f(9) = 35
后面的全递增4
*/
