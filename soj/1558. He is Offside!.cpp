#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int a, d, cn, b[20], c[20];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    while (scanf( "%d%d", &a, &d ) && a != 0 && d != 0)
    {
        for (int i = 0; i < a; i ++)
            scanf( "%d", &b[i] );
        for (int i = 0; i < d; i ++)
            scanf( "%d", &c[i] );
        sort(b, b+a);
        sort(c, c+d);
        cn = 0;
        for (int i = 0; i < d; i ++)
        {
            if (c[i] > b[0])
               break;
            cn ++;
        }
        cn < 2 ? puts( "Y" ) : puts( "N" );
    }

    return 0;
}
