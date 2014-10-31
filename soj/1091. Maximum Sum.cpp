#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 50000;

int t, n, minX, ans;
int a[MAX], sum[MAX], rsum[MAX];
int maxd[MAX], rmaxd[MAX];

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --)
	{
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
			scanf( "%d", &a[i] );

		sum[0] = a[0];
		rsum[n-1] = a[n-1];
		for (int i = 1; i < n; i ++)
		{
			sum[i] = sum[i-1] + a[i];
			rsum[n-1-i] = rsum[n-i] + a[n-1-i];
		}

		maxd[0] = a[0];
		minX = 0 < sum[0] ? 0 : sum[0];
		for (int i = 1; i < n; i ++)
		{
			maxd[i] = max(maxd[i-1], sum[i]-minX);
			if (sum[i] < minX)
				minX = sum[i];
		}
		
		rmaxd[n-1] =  a[n-1];
		minX = 0 < rsum[n-1] ? 0 : rsum[n-1];
		for (int i = n-2; i >= 0; i --)
		{
			rmaxd[i] = max(rmaxd[i+1], rsum[i]-minX);
			if (rsum[i] < minX)
				minX = rsum[i];
		}

		ans = maxd[0] + rmaxd[1];
		for (int i = 1; i < n-1; i ++)
			if (maxd[i] + rmaxd[i+1] > ans)
				ans = maxd[i] + rmaxd[i+1];
		printf( "%d\n", ans );
	}

	return 0;
}

/*
设maxd[n]为前n个数的最大子序列和

maxd[n]=max{ maxd[n-1], sum[n]-minX }
其中，minX=min{sum[i] |   1<=i<n}

同理，设rmaxd[n]为从n到序列完的最大子序列和

则答案为max{ maxd[i]+rmaxd[i+1] },时间复杂度为O(n)
*/
