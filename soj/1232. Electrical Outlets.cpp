#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k, o, answer;
    scanf( "%d", &n );
    while (n --)
    {
        answer = 0;
        scanf( "%d", &k );
        for (int i = 0; i < k; i ++)
        {
            scanf( "%d", &o );
            answer += o;
        }
        printf( "%d\n", answer - k + 1 );
    }
    return 0;
}
