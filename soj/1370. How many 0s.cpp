#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long n, m, fn, fm;
//看了数论相关知识点才会。。。
long long count0(long long number)
{
	long long cn = 1, ba = 1;
	if (number < 10)	return 1;
	if (number%10 != 0)		cn += ba * (number/10);
	else	cn += ba * (number/10 - 1) + 1;
	ba *= 10;
	while (number/ba >= 10)
	{
		if (number/ba%10 != 0)		cn += ba * (number/ba/10);
		else	cn += ba * (number/ba/10 - 1) + 1 + (number%ba);
		ba *= 10;
	}
	return cn;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%lld%lld", &n, &m) && n >= 0 && m >= 0)
	{
		fn = n ? count0(n-1) : 0;
		fm = m ? count0(m) : 1;
		printf( "%lld\n", fm-fn );
	}

	return 0;
}
