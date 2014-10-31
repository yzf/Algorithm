#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool flag;
int n, d, x, sum[100];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &n, &d ) && n != 0 && d != 0)
	{
		memset(sum, 0, sizeof(sum));
		flag = false;
		int k = d;
		while (k --)
		{
			for (int i = 0; i < n; i ++)
			{
				scanf( "%d", &x );
				sum[i] += x;
				if (sum[i] == d)
					flag = true;
			}
		}
		if (flag)
			printf( "yes\n" );
		else
			printf( "no\n" );
	}
	
    return 0;
}

