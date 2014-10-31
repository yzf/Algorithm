#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

double b, n;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	for (scanf( "%lf%lf", &b, &n ); b != 0.0 && n != 0.0; scanf( "%lf%lf", &b, &n ))
	{
		double ans = 1.0;
		while (true)
		{
			if (pow(ans, n) >= b)
				break;
			ans ++;
		}
		if ((pow(ans, n) - b) > (b - pow(ans-1, n)))
			ans --;

		printf( "%.lf\n", ans );
		
	}

    return 0;
}
