#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, step, pre, ne, sum[100010];
//贪心一下就行了 
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    scanf( "%d", &n );
    sum[0] = 0;
    for (int i = 1; i <= n; i ++)
    {
        scanf( "%d", &sum[i] );
        sum[i] += sum[i-1];
    }
    step = pre = 0;
    ne = 1;
    while (pre != n)
    {
        for ( ; sum[ne] < 0 && ne <= n; ne ++)
            ;
        step += (ne-pre-1) * 3 + 1;
        pre = ne ++;
    }
    printf( "%d\n", step );
    
    return 0;
}
