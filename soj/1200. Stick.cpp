#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int n;
    for (scanf("%d", &n); n != 0; scanf("%d", &n))
    {
        int stickLength[101] = {0};
        for (int i = 0; i < n; i ++)
            scanf( "%d", &stickLength[i] );
        
        sort(stickLength, stickLength+n);
        
        for (int index = 0; ;index += 2)
        {
            if (stickLength[index] != stickLength[index+1])
            {
                printf( "%d\n", stickLength[index] );
                break;                   
            }
        }
    }
    
    return 0;
}
