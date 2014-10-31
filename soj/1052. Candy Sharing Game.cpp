#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 101;

int n, roundNumber, endNumber;
int pre[MAX], now[MAX]; 

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf("%d", &n) && n != 0)
	{
		int i;
		for (i = 0; i < n; i ++)
		{
			scanf( "%d", &now[i] );
			pre[i] = now[i];
		}

		roundNumber = 0;
		while (true)
		{
			sort(now, now+n);
			if (now[0] == now[n-1])
				break;

			for (i = 0;i < n;i++)
			{
				now[(i+1)%n] = pre[(i+1)%n]/2 + pre[i]/2;
				if(now[(i+1)%n]%2!=0) 
				now[(i+1)%n]++;
			}
			for (i = 0; i < n; i ++)
				pre[i] = now[i];
			
			roundNumber ++;
		}
		endNumber = now[0];

		printf( "%d %d\n", roundNumber, endNumber );
	}

    return 0;
}
