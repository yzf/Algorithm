#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
/*
����������ȫͼ�в�ͬ������Ŀk�����⻹Ҫ����һ��ȫ����(n-1)!, ��Ϊ��n-1���ߡ�
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
