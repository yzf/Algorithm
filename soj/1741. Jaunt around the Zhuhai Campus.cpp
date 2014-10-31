#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n;
double x[1001], y[1001], ans;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		ans = 0.0;
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
			scanf( "%lf%lf", &x[i], &y[i] );

		for (int i = 1; i < n; i ++)
			ans += (y[i]+y[i-1]) * (x[i]-x[i-1]) / 2.0;
		printf( "%.1lf\n", ans );
	}

    return 0;
}
