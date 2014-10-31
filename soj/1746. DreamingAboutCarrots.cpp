#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a, b, c, d, ans;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d%d%d", &a, &b, &c, &d ) != EOF)
	{
		if (a == c)
			ans = d > b ? (d-b-1) : (b-d-1);
		else
		{
			ans = 0;
			int ma = max(a, c);
			int mi = min(a, c);
			for (int i = mi+1; i < ma; i ++)
				if (((i-a)*(d-b)%(c-a) == 0) && (b + (i-a)*(d-b)/(c-a)) >= 0)
					ans ++;
		}
		printf( "%d\n", ans );
	}

    return 0;
}
