#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1 << 20;
int cases, n, d, cn, ans, cn2, father[501];
struct Edge {
    int city1, city2;
    int dist;
    bool operator < (const Edge &rhs) const 
    {
        return dist < rhs.dist;
    }
} edge[130000];

void make_set()
{
    for (int i = 1; i <= n; i ++)
        father[i] = i;
}

int find_set(int &x)
{
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}

bool union_set(int &x, int &y)
{
    int fx = find_set(x);
    int fy = find_set(y);
    if (fx != fy)    
    {
        father[fy] = fx;
        return true;
    }
    return false;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    scanf( "%d", &cases );
    while (cases --)
    {
        scanf( "%d", &n );
        cn = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                scanf( "%d", &d );
                if (j > i)
                {
                    edge[cn].city1 = i;
                    edge[cn].city2 = j;
                    edge[cn].dist = d;  
                    cn ++;
                }  
            }
            
        make_set();
        sort(edge, edge+cn);
        
        ans = 0;   cn2 = 1;
        for (int i = 0; i < cn && cn2 < n; i ++)
        {
            if (union_set(edge[i].city1, edge[i].city2))
            {
                ans = max(ans, edge[i].dist);
                cn2 ++;
            }
        }
        printf( "%d\n", ans );
        
        if (cases > 0)  printf( "\n" );
    }
    
    return 0;
}
