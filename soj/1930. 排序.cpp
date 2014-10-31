#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n, cn, a[100];

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
			scanf( "%d", &a[i] );

		cn = 0;
		for (int i = 0; i < n-1; i ++)
		{
			int k = i;
			for (int j = i+1; j < n; j ++)
			{
				if (a[k] > a[j])
				{
					k = j;
					cn ++;
				}
			}
			swap(a[k], a[i]);
		}
		printf( "%d\n", cn );
	}

    return 0;
}
