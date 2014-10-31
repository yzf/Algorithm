#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

string a, b;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    cin >> a >> b;
    int len1 = a.length();
    int len2 = b.length();
    int ans = 0;

    for (int i = 0; i < len1-1; i ++)
        for (int j = 1; j < len2; j ++)
            if (a[i] == b[j] && a[i+1] == b[j-1])
            {
                ans ++;
                break;
            }
        
    printf( "%d", (1 << ans) );

    return 0;
}
