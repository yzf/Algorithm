#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int t;
        
    scanf( "%d", &t );
    
    for (int i = 1; i <= t; i ++)
    {
        int sum = 0, add = 0, len;
        char str[90];
        
        scanf( "%s", str );
        
        len = strlen(str);
        for (int j = 0; j < len; j ++)
            if (str[j] == 'O')
            {
                add ++;
                sum += add;
            }
            else
                add = 0;
    
        printf( "%d\n", sum );
    }
    
    return 0;
}
