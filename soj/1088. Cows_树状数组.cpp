#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
//使用树状数组解决。。。 
const int MAX = 100005;
int n, s, e, maxn, c[MAX], ans[MAX];

struct Cow {
	int s, e;
	int num;
	Cow() {	s = -1; e = -1; num = -1;	}
	Cow(int ts, int te, int tnum) : s(ts), e(te), num(tnum){}
} cow[MAX];

bool cmp(const Cow &a, const Cow &b)
{
	if (a.e == b.e)		return a.s < b.s;
    else	return a.e > b.e;
}

int lowBit(int pos)
{
	return pos & (-pos);
}

void add(int pos, int num)
{
	while (pos < maxn)
	{
		c[pos] += num;
		pos += lowBit(pos);
	}
}

int getSum(int pos)
{
	int sum = 0;
	if (pos <= 0)	return 0;
	while (pos > 0)
	{
		sum += c[pos];
		pos -= lowBit(pos);
	}
	return sum;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) && n != 0)
	{
		memset(c, 0, sizeof(c));

		maxn = 0;
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d%d", &s, &e );
			cow[i] = Cow(s+1, e+1, i);
			if (e+1 > maxn)
				maxn = e+1;
		}

		sort(cow, cow+n, cmp);
		for (int i = 0; i < n; i ++)
		{
			if (i != 0 && cow[i].s == cow[i-1].s && cow[i].e == cow[i-1].e)
				ans[ cow[i].num ] = ans[ cow[i-1].num ];
			else
				ans[ cow[i].num ] = getSum(cow[i].s);

			add(cow[i].s, 1);
		}
		for (int i = 0; i < n; i ++)
			printf( "%d\n", ans[i] );
	}

	return 0;
}
