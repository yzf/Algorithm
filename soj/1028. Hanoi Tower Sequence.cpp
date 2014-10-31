#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int t;
    string p;
    
    scanf( "%d", &t );
    
    for (int i = 1; i <= t; i ++)
    {
        int ans = 1;
        cin >> p;
        while (true)
        {
            int j;
            for (j = p.length()-1; j >= 0; j --)
            {
                if ((p[j] - '0')%2)
                    break;
                
                if ((j == 0 && !((p[j] - '0')%2)) || (!((p[j-1] - '0')%2) && !((p[j] - '0')%2)))
                    p[j] = (p[j] - '0')/2 + '0';
                else if (((p[j-1] - '0')%2) && !((p[j] - '0')%2))
                {
                     p[j-1] --;
                     p[j] = (p[j] - '0' + 10) / 2 + '0';
                }
                    
            }
            if (j >= 0)
                break;
            else
                ans ++;
        }
        
        printf( "Case %d: %d\n", i, ans );
        
        if (i != t)
            printf( "\n" );
    }
    
    return 0;
}
