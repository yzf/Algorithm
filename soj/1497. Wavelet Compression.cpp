#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, num[300], ans[300], cn;

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	while (scanf( "%d", &n ) && n != 0)
	{
		for (int i = 1; i <= n; i ++)
		{
			scanf( "%d", &num[i] );
			ans[i] = num[i];
		}

		cn = 1;
		while (cn < n)
		{
			int j = 1;
			for (int i = 1; i <= cn; i ++)
			{
				int temp1, temp2;
				temp1 = (num[i] + num[cn+i]) / 2;
				temp2 = (num[i] - num[cn+i]) / 2;
				ans[j ++] = temp1;		ans[j ++] = temp2;
			}
			cn <<= 1;
			for (int i = 1; i <= n; i ++)
				num[i] = ans[i];
		}

		printf( "%d", ans[1] );
		for (int i = 2; i <= n; i ++)
			printf( " %d", ans[i] );
		printf( "\n" );
	}
		
    return 0;
}
