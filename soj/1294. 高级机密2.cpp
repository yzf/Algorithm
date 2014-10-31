#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    // (x*y) % z = x * (y%z) % z
    int a, b, c, answer;
    scanf( "%d%d%d", &a, &b, &c );
    answer = 1;
    for (int i = 1; i <= b; i ++)
        answer = answer*a % c;
    printf( "%d\n", answer );
    
    return 0;
}
