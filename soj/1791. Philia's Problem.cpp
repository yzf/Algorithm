#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, d, m, y, a, dif;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    scanf( "%d", &cases );
    while (cases --)
    {
        scanf( "%d%d%d", &m, &d, &y );
        int tm = m, ty = y;
        if (m == 1 || m == 2)
        {
            m += 12;  y --;
        }
        a = (d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
        m = tm;  y = ty;
        dif = a < 6 ? 6-a : 7;
        int temp = month[m-1];
        if (m == 2 && ((y%4 == 0 && y%100 != 0) || y%400 == 0))
            temp ++;
        if (d+dif <= temp)
        {
            d += dif;
        } 
        else
        {
            d = (d+dif) % temp;
            m ++;    
            if (m > 12)
            {
                m -= 12;
                y ++;
            }
        }

        if (m < 10)  printf( "0%d", m );
               else  printf( "%d", m );
        if (d < 10)  printf( " 0%d ", d );
               else  printf( " %d ", d );
        printf( "%d\n", y );    
    }
    
    return 0;
}
