#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 110;
int n, ans, data[MAX], _max[MAX], _min[MAX];
//_max[i]表示数列1到i的最大值，_min[i]表示数列i到n的最小值
int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF) {
		_min[n+1] = 20000000;
		_max[0] = -20000000;
		for (int i = 1; i <= n; i ++)
			scanf( "%d", &data[i] );

		for (int i = 1; i <= n; i ++) 
			_max[i] = max(_max[i-1], data[i]);
		for (int i = n; i >= 1; i --)
			_min[i] = min(_min[i+1], data[i]);

		ans = 0;
		for (int i = 1; i <= n; i ++)
			if (data[i] >= _max[i-1] && data[i] <= _min[i+1])
				ans ++;
		printf( "%d\n", ans );
	}

	return 0;
}
