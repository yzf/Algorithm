#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, m, a, b, cur, ne, cn, ans, in[10001], money[10001];
vector<int> out[10001];
queue<int> que;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    scanf( "%d%d", &n, &m );
    
    memset(in, 0, (n+1)*sizeof(int));
    memset(money, 0, (n+1)*sizeof(int));

    while (m --)
    {
        scanf( "%d%d", &a, &b );
        in[a] ++;
        out[b].push_back(a);
    }
    
    cn = 0;
    for (int i = 1; i <= n; i ++)
        if (in[i] == 0)
        {
            que.push(i);
            cn ++;
        }
    
    ans = n*100;
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        for (int i = 0; i < out[cur].size(); i ++)
        {
            ne = out[cur][i];
            -- in[ne];
            money[ne] = max(money[ne], money[cur]+1);
            if (in[ne] == 0)
            {
                que.push(ne);
                ans += money[ne];
                cn ++;
            }
        }
    }
    
    if (cn != n)
        printf( "Poor Xed\n" );
    else
        printf( "%d\n", ans );   
        
    return 0;
}
