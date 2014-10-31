#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const double kToP = 2.2046;
const double pToK = 0.4536;
const double lToG = 0.2642;
const double gToL = 3.7854;

int cases;
double n, ans;
char unit[5], ansUnit[5];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	for (int i = 1; i <= cases; i ++)
	{
		scanf( "%lf%s", &n, unit );
		if (unit[0] == 'k')
		{
			ans = n * kToP;
			ansUnit[0] = 'l';
			ansUnit[1] = 'b';
			ansUnit[2] = '\0';
		}
		else if (unit[1] == 'b' )
		{
			ans = n * pToK;
			ansUnit[0] = 'k';
			ansUnit[1] = 'g';
			ansUnit[2] = '\0';
		}
		else if (unit[0] == 'l')
		{
			ans = n * lToG;
			ansUnit[0] = 'g';
			ansUnit[1] = '\0';
		}
		else
		{
			ans = n * gToL;
			ansUnit[0] = 'l';
			ansUnit[1] = '\0';
		}
		
		printf( "%d %.4lf %s\n", i, ans, ansUnit );
	}

    return 0;
}
