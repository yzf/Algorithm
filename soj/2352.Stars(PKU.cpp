#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 32010;
int n, x, y, ans[MAX], c[MAX];

void modify(int pos, int num)
{
	while (pos < MAX)
	{
		c[pos] += num;
		pos += pos & (-pos);
	}
}

int sum(int pos)
{
	int s = 0;
	while (pos > 0)
	{
		s += c[pos];
		pos -= pos & (-pos);
	}
	return s;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	memset(ans, 0, sizeof(ans));
	memset(c, 0, sizeof(c));

	scanf( "%d", &n );
	for (int i = 0; i < n; i ++)
	{
		scanf( "%d%d", &x, &y );
		x++;
		ans[ sum(x) ] ++;
		modify(x, 1);
	}
	for (int i = 0; i < n; i ++)
		printf( "%d\n", ans[i] );

	return 0;
}
