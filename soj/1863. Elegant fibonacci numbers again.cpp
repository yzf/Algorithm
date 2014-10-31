#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases;
long long n, m;
long long temp1[2][2] = {1, 1, 1, 0}, temp2[2][2], f[2][2];
/*
矩阵相乘满足，A^n = A^(n/2) * A^(n/2) (n为偶数）,最后得到迭代关系:                  
n为奇数时，F(N) = F((N-1)/2) * F((N-1)/2) * {1, 1, 1, 0}
n为偶数时，F(N) = F(N/2) * F(N/2)
*/
void matrixProduce(long long a[][2], long long b[][2], long long c[][2], long long &m)
{
	c[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % m;
	c[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % m;
	c[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % m;
	c[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % m;
}

void getFibonacci(long long c[][2], long long n, long long &m)
{
	if (n == 1)
		memcpy(c, temp1, sizeof(temp1));
	else if (n & 1)
	{
		getFibonacci(c, (n-1) >> 1, m);
		memcpy(temp2, c, sizeof(temp2));
		matrixProduce(temp2, temp2, c, m);
		memcpy(temp2, c, sizeof(temp2));
		matrixProduce(temp1, temp2, c, m);
	}
	else
	{
		getFibonacci(c, n >> 1, m);
		memcpy(temp2, c, sizeof(temp2));
		matrixProduce(temp2, temp2, c, m);
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%lld%lld", &n, &m );
		if (n == 0 || n == 1)
			printf( "%lld\n", n );
		else
		{
			getFibonacci(f, n-1, m);
			printf( "%lld\n", f[0][0] );
		}
	}

    return 0;
}
