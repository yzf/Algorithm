#include <cstdio>

int main()
{
    int t, n, a, mini, maxu;
    scanf( "%d", &t );
    while (t --)
    {
        mini = 1000000;
        maxu = -1;
        scanf( "%d", &n );
        for (int i = 0; i < n; i ++)
        {
            scanf( "%d", &a );
            if (a < mini)
                mini = a;
            if (a > maxu)
                maxu = a;
        }
        printf( "%d\n", (maxu-mini) << 1 );
    }
    
    return 0;
}
