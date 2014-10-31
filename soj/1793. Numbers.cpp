#include <iostream>
#include <cstdio>  
#include <cmath>  

using namespace std;  
  
int x, y, k1, k2, temp, a, b;

int gcd(int x, int y)  
{  
    if (x%y == 0)  
        return y;  
    else  
        return gcd(y, x%y);  
}
  
int main()  
{  
	//freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
    while(scanf("%d%d", &x, &y) && x != 0)  
    {
		temp = y / x;
		for (k1 = (int)sqrt((double)temp); k1 >= 1; k1 --)
		{
			k2 = temp / k1;
			if (temp % k1 == 0 && gcd(k1, k2) == 1)
				break;
		}
		a = k1 * x;		b = k2 * x;
		printf( "%d %d %d\n", b-a, a, b );
    } 

    return 0;  
}  

/*
��x=GCD(a,b),y=LCM(a,b)��
a=x*k1
b=x*k2, ���� GCD(k1,k2)=1
��y=x*k1*k2;
��min(a,b),��min(k1,k2)
*/
