#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 20000;
int cases, n, m, ans;
int a[MAX], curb, preb;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		ans = 0;
		scanf( "%d%d", &n, &m );
		for (int i = 0; i < n; i ++)
			scanf( "%d", &a[i] );

		sort(a, a+n);
		int index = 0;
		preb = -1000000;
		while (m --)
		{
			scanf( "%d", &curb );
			if (curb < preb)
				index = 0;
			while (curb >= a[index])
				index ++;
			if (index < n)
				ans += n - index;
			preb = curb;
		}
		printf( "%d\n", ans );
	}

    return 0;
}
