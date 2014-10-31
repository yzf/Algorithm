#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool visited[300];
int cases, n, m, a, b, len, dist[300];
int l[300][300];
vector<int> con[300];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	while (cases --)
	{
		memset(visited, false, sizeof(visited));
		memset(l, -1, sizeof(l));
		scanf( "%d%d", &n, &m );
		for (int i = 1; i <= n; i ++)
		{
			con[i].clear();
			dist[i] = -1;
		}
		dist[1] = 0;

		while (m --)
		{
			scanf( "%d%d%d", &a, &b, &len );
			if (l[a][b] < 0 || len < l[a][b])
			{
				l[a][b] = l[b][a] = len;
				con[a].push_back(b);
				con[b].push_back(a);
			}
		}

		for (int i = 0; i < con[1].size(); i ++)
			dist[ con[1][i] ] = l[1][ con[1][i] ];
		visited[1] = true;
		while (true)
		{
			int mi = 1 << 30, ne = 0;
			for (int j = 1; j <= n; j ++)
				if (!visited[j] && dist[j] > 0 && dist[j] < mi)
				{
					mi = dist[j];
					ne = j;
				}
			if (ne == 0)	break;
			
			visited[ne] = true;
			for (int j = 0; j < con[ne].size(); j ++)
			{
				if ((dist[ con[ne][j] ] < 0 || dist[ne]+l[ne][ con[ne][j] ] < dist[ con[ne][j] ]))
					dist[ con[ne][j] ] = dist[ne] + l[ne][ con[ne][j] ];
			}
		}
		printf( "%d\n", dist[n] );
	}

	return 0;
}
