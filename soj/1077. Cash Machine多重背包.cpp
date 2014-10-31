#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100001;
int cash, N, n, d, ans, w[MAX], cn;
bool flag[MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &cash ) != EOF)
	{
		cn = 0, ans = 0;
		flag[0] = true;
		for (int i = 1; i <= cash; i ++)
			flag[i] = false;
		
		scanf( "%d", &N );
		while (N --)//压缩，使用2的次方
		{
			scanf( "%d%d", &n, &d );
			int j = 0;
			while (n > 0)
			{
				int temp = 1 << (j ++);
				if (n >= temp)
				{
					w[cn ++] = temp * d;
					n -= temp;
				}
				else
				{
					w[cn ++] = n * d;
					n = 0;
				}
			}
		}
		for (int i = 0; i < cn; i ++)
			for (int j = cash; j >= w[i]; j --)
				if (flag[j-w[i]])
				{
					flag[j] = true;
					if (j > ans)
						ans = j;
				}
		printf( "%d\n", ans );
	}

    return 0;
}
