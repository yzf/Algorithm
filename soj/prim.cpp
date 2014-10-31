#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1 << 20;
int cases, n, dis[501][501], dist[501], ans, ne, id;
bool visited[501];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    scanf( "%d", &cases );
    while (cases --)
    {
        memset(visited, false, sizeof(visited));
        scanf( "%d", &n );
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                scanf( "%d", &dis[i][j] );
                
        visited[1] = true;
        dist[1] = MAX;
        for (int i = 2; i <= n; i ++)
            dist[i] = dis[1][i];
        ans = 0;
        while (true)
        {
            id = -1;    ne = MAX;
            for (int i = 1; i <= n; i ++)
                if (!visited[i] && dist[i] < ne)
                {
                    ne = dist[i];
                    id = i;
                }
                
            if (id == -1)  break;
            visited[id] = true;
            ans = max(ans, dist[id]);
            dist[id] = MAX;
            for (int i = 1; i <= n; i ++)
                if (!visited[i] && dis[id][i] < dist[i])
                    dist[i] = dis[id][i];
        }
        printf( "%d\n", ans );
        if (cases > 0)  printf( "\n" );
    }
    
    return 0;
}
