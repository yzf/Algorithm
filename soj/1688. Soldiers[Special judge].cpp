#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cases, n, height[10000], ans[10000];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
			scanf( "%d", &height[i] );

		sort(height, height+n);
		int head = 0, tail = n-1, index = 0;
		while (head < tail)
		{
			ans[index ++] = height[head ++];
			ans[index ++] = height[tail --];
		}
		if (head == tail)
			ans[index] = height[head];

		for (int i = 0; i < n-1; i ++)
			printf( "%d ", ans[i] );
		printf( "%d\n", ans[n-1] );
	}
	
	return 0;
}
