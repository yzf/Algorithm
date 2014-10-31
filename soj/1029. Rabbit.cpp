#include <iostream>
#include <cstdio>

using namespace std;

const long long ten15 = (long long) 10000000*100000000;

struct BigNumber {
    long long high;
    long long low;
} ;

void initialization(BigNumber &a, int number)
{
    a.high = 0;
    a.low = number;
}

void addBigNumber(BigNumber &a, BigNumber &b, BigNumber &answer)
{
    answer.low = a.low + b.low;
    answer.high = a.high + b.high + answer.low / ten15;
    answer.low = answer.low % ten15;
}

int countDigit(long long number)
{
    int digit = 1;
    while (number >= 10)
    {
        digit ++;
        number /= 10;
    }
    return digit;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int m, d;
    for (scanf( "%d%d", &m, &d); m != 0 && d != 0; scanf( "%d%d", &m, &d))
    {
        BigNumber rabbitNumber[101];
        for (int i = 0; i <= m; i ++)
            initialization(rabbitNumber[i], i+1);
            
        for (int i = m+1; i <= d; i ++)
            addBigNumber(rabbitNumber[i-1], rabbitNumber[i-m], rabbitNumber[i]);
            
        if (!rabbitNumber[d].high)
            printf( "%lld\n", rabbitNumber[d].low );
        else
        {
            int addedZero;
            addedZero = 15 - countDigit(rabbitNumber[d].low);
            printf( "%lld", rabbitNumber[d].high );
            for (int i = 1; i <= addedZero; i ++)
                printf( "%d", 0);
            printf( "%lld\n", rabbitNumber[d].low );
        }
    }
    
    return 0;
}
