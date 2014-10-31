#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int cases, n, ans;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		ans = 1;
		scanf( "%d", &n );
		int m = sqrt((double)n);
		while (m != 1)
		{
			if (n % (m*m) == 0)
			{
				ans *= m;
				n /= m;
				m = sqrt((double)n);
			}
			m --;
		}
		
		printf( "%d\n", ans );
	}	

    return 0;
}
