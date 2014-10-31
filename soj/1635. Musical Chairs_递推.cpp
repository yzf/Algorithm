#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int ans, n, d;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
 
    while (scanf("%d%d", &n, &d) && d != 0) {
        ans = 0;
        for (int i = 2; i <= n; i ++) {
            ans = (ans + d) % i;//f[n] = ( f[n-1]%n + d ) % n = (f[n-1]+d) % n
        }
        printf( "%d %d %d\n", n, d, ans+1 );
    }

    return 0;
}
