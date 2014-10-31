#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int mod(string &veryLongInteger, int divisor)
{
    int temp, index;
    temp = veryLongInteger[0] - '0';
    index = 1;
    while (true)
    {
        while (temp < divisor)
        {
            if (index == veryLongInteger.size())
                return temp;
            temp = temp * 10 + veryLongInteger[index ++] - '0';
        }
        temp = temp % divisor;
    }
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int t;
    scanf( "%d", &t );
    
    while (t --)
    {
        int n;
        int basis[101];
        string veryLongInteger;
        
        scanf( "%d", &n );
        
        for (int i = 0; i < n; i ++)
            scanf( "%d", &basis[i] );    
            
        cin >> veryLongInteger;
        
        printf( "(" );
        for (int i = 0; i < n-1; i ++)
            printf( "%d,", mod(veryLongInteger, basis[i]) );
        printf( "%d)\n", mod(veryLongInteger, basis[n-1]) );
    }
    
    return 0;
}
