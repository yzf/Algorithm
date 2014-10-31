#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 30000;
int w, n, ans, a[MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	int j = 1;
	while (scanf( "%d", &w ) != EOF)
	{
		if (j++ != 1)
			printf( "\n" );

		ans = 0;
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
			scanf( "%d", &a[i] );

		sort(a, a+n);
		int be = 0, en = n-1;
		while (be <= en)
		{
			if (a[be] + a[en] <= w)
				be ++;

			en --;
			ans ++;
		}
		printf( "%d\n", ans );
	}

    return 0;
}
