#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    
    int a, b, c, answer;
    
    scanf( "%d%d%d", &a, &b, &c );
    //b=b0+b1*2^1+b2*2^2+...+bn*2^n
    answer = 1;
    while (b != 0)
    {
        if ((b & 1) == 1)
        {
            answer = answer * a;
            answer = answer % c;
        }
        a = a * a;
        a = a % c;
        b = b >> 1;
    }
    printf( "%d\n", answer );
    
    return 0;
}
