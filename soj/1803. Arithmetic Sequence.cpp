#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const long long MAX = 1000000007;
int cases;
long long n, a, da, b, db, s;

long long module(long long num)
{
    if (num > 0)  return num % MAX;
    
    long long ans = num % MAX;
    ans += MAX;
    ans = ans % MAX;
    return ans;
}
//化简后得 s = n*a*b + n*(n-1)/2*a*db + n*(n-1)/2*b*da + n*(n-1)*(2*n-1)/6*da*db;
//n*(n-1)*(2*n-1)/6*da*db这一项的 模 最易错。。。 
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    scanf( "%d", &cases );
    while (cases --)
    {
        scanf( "%lld%lld%lld%lld%lld", &n, &a, &da, &b, &db );
        
        s = module(module(n*a)*b);
        
        s += module(module(module(n*(n-1)/2)*a)*db);
        s = module(s);
        
        s += module(module(module(n*(n-1)/2)*b)*da);
        s = module(s);
        
        long long temp1 = n*(n-1), temp2, temp3;
        int bit = 6;
        if (temp1 % 2 == 0)     
        {
            temp1 /= 2;  bit /= 2;
        }
        if (temp1 % 3 == 0)
        {
            temp1 /= 3;  bit /= 3;
        }
        temp2 = (2*n-1) / bit;
        temp3 = module(module(temp1)*module(temp2));
        s += module(module(temp3*da)*db);
        s = module(s);
        
        printf( "%lld\n", s );
    }
    
    return 0;
}
