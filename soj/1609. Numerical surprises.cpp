#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 2010;
int cases; 
long long n, ans, num[MAX];
char p[MAX];

void module()
{
	memset(num, 0, sizeof(num));

	int len = 0;
	int i;
	for (i = strlen(p)-1; i >= 0; i --)
		num[len ++] = p[i] - '0';
	len --;
	ans = 0;	i = len;
	while (i > 0)
	{
		num[i-1] += (num[i] % n) * 10;
		i --;
	}
	ans = num[0] % n;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%lld%s", &n, p );
		module();
		printf( "%lld\n", ans );
	}

	return 0;
}
