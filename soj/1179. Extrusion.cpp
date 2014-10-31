#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX = 1000;
int n;
double v, s, x[MAX], y[MAX];
//多边形面积计算。。。 
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) && n >= 3)
	{
		for (int i = 0; i < n; i ++)
			scanf( "%lf%lf", &x[i], &y[i] );
		scanf( "%lf", &v );

		x[n] = x[0];	
		y[n] = y[0];
		s = 0.0;
		for (int i = 0; i < n; i ++)
			s += x[i]*y[i+1] - x[i+1]*y[i];

		printf( "BAR LENGTH: %.2lf\n", 2*v/fabs(s) );
	}

    return 0;
}
