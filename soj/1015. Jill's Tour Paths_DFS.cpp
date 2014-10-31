#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 30;
int nv, nr, dist[MAX][MAX], sv, dv, maxdist, a, b, d;
int total, cases, ans[MAX];
bool visited[MAX];
struct Route {
    int len;
    int cities[MAX];
    int dis;
    bool operator < (const Route rhs) const {
        if (dis != rhs.dis) return dis < rhs.dis;
        else {
            for (int i = 0; i < len && i < rhs.len; i ++)
                if (cities[i] != rhs.cities[i])
                    return cities[i] < rhs.cities[i];
        }
    }
} route[200];

void dfs(int cityCn, int curCity, int distance)
{
    if (distance > maxdist) return ;
    if (curCity == dv) {
        route[total].len = cityCn;
        route[total].dis = distance;
        for (int i = 0; i < cityCn; i ++) 
            route[total].cities[i] = ans[i];
        total ++;
        return ;
    }
    for (int i = 1; i <= nv; i ++) {
        if (!visited[i] && dist[curCity][i] != -1) {
            visited[i] = true;
            ans[cityCn] = i;
            dfs(cityCn+1, i, distance+dist[curCity][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
 
    cases = 1;
    while (scanf( "%d", &nv ) && nv != -1) {

        if (cases != 1)     
            printf("\n");
        memset(dist, -1, sizeof(dist));
        memset(visited, false, sizeof(visited));
        total = 0;

        scanf( "%d", &nr );
        while (nr --) {
            scanf( "%d%d%d", &a, &b, &d );
            dist[a][b] = dist[b][a] = d;
        }
        scanf( "%d%d%d", &sv, &dv, &maxdist );

        visited[sv] = true;
        ans[0] = sv;
        dfs(1, sv, 0);
        sort(route, route+total);

        printf( "Case %d:\n", cases ++ );
        if (total == 0) {
            printf( " NO ACCEPTABLE TOURS\n" );
            continue;
        }
        for (int i = 0; i < total; i ++) {
            printf( " %d:", route[i].dis );
            for (int j = 0; j < route[i].len; j ++)
                printf( " %d", route[i].cities[j] );
            printf("\n");
        }
    }

    return 0;
}
