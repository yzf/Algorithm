#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1 << 30;
bool flag[60];
int p, r, fr, to, len, ans;
int dist[60], routes[60][60];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &p ) && p != 0)
	{
		ans = 0;
		memset(flag, false, sizeof(flag));
		memset(routes, -1, sizeof(routes));
		memset(dist, -1, sizeof(dist));
		scanf( "%d", &r );
		while (r --)
		{
			scanf( "%d%d%d", &fr, &to, &len );
			if (routes[fr][to] < 0 || len < routes[fr][to])
				routes[fr][to] = routes[to][fr] = len;
		}

		for (int i = 1; i <= p; i ++)
			dist[i] = routes[1][i];
		flag[1] = true;
		int left = p-1;
		while (left > 0)
		{
			int minLen = MAX;
			int ne = -1;
			for (int i = 1; i <= p; i ++)
				if (!flag[i] && dist[i] > 0 && dist[i] < minLen)
				{
					minLen = dist[i];
					ne = i;
				}
			
			ans += minLen;
			dist[ne] = -1;
			flag[ne] = true;
			for (int i = 1; i <= p; i ++)
			{
				if (!flag[i] && ((routes[ne][i] > 0 && routes[ne][i] < dist[i]) || dist[i] < 0))		
					dist[i] = routes[ne][i];
			}
			left --;
		}

		printf( "%d\n", ans );
	}

	return 0;
}
