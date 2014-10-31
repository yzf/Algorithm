#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, ans, height[20];
int order[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    scanf( "%d%d", &n, &k );
    for (int i = 0; i < n; i ++)
        scanf( "%d", &height[i] );
    
    int i;
    ans = 0;
    do {
        order[n] = order[0];
        for (i = 0; i < n; i ++)
            if (abs(height[ order[i] ] - height[ order[i+1] ]) > k)
                break;
        if (i == n)   ans ++; 
    } while (next_permutation(order, order+n));
    printf( "%d\n", ans/n );
    
    return 0;
}
