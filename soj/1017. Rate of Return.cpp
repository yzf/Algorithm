#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, tmonth;
double tmoney, sum;
struct Investment {
	int month;
	double money;
} investment[12];
//二分法求方程解 
int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	int cases = 1;
	while (scanf( "%d", &n ) && n != -1)
	{
		if (cases != 1)	printf( "\n" );

		int i;
		for (i = 0; i < n; i ++)
			scanf( "%d%lf", &investment[i].month, &investment[i].money );
		scanf( "%d%lf", &tmonth, &tmoney );

		for (i = 0; i < n; i ++)
			investment[i].month = tmonth+1-investment[i].month;

		double up, mid, down;
		up = 2.0;	down = 1.0;
		mid = (up + down) / 2;
		while ((mid-down) > 0.000001)
		{
			sum = 0.0;
			for (i = 0; i < n; i ++)
				sum += investment[i].money * pow(mid, investment[i].month);

			if (sum < tmoney)
				down = mid;
			else
				up = mid;
			mid = (up + down) / 2;
		}

		printf( "Case %d: %.5lf\n", cases ++, mid-1.0 );
	}
    
    return 0;
}
