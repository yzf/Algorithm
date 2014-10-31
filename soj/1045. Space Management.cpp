#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int desk[2001][1001];
int cases, doc, ans, x, y, w, h;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		ans = 0;
		memset(desk, 0, sizeof(desk));
		scanf( "%d", &doc );
		for (int i = 0; i < doc; i ++)
		{
			scanf( "%d%d%d%d", &x, &y, &w, &h );
			for (int j = x; j < x+w; j ++)
			{
				desk[j][y] += 1;
				desk[j][y+w] += -1;
			}
		}

		int flag;
		for (int i = 0; i < 2000; i ++)
		{
			flag = 0;
			for (int j = 0; j < 1000; j ++)
			{
				flag += desk[i][j];
				if (flag > 0)
					ans ++;
			}
		}
		printf( "%d\n", ans );
	}

    return 0;
}
