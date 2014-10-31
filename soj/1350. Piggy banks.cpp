#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1000001;
int n, ans, color;//把同一个环染成相同颜色 
int flag[MAX], ne[MAX];//ne[i]表示钥匙 i 在 ne[i]中 
//可以转化为计算有向图的环的个数
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF)
	{
		for (int i = 1; i <= n; i ++)//由于n可能远小于MAX，所以直接用循环初始化会更快
			flag[i] = -1;
		ans = 0;
		color = 1;

		for (int i = 1; i <= n; i ++)
		{
			scanf( "%d", &ne[i] );
			if (ne[i] == i)
			{
				flag[i] = color ++;
				ans ++;
			}
		}

		for (int i = 1; i <= n; i ++)
		{
			if (flag[i] > 0)
				continue;
				
			color ++;
			int index = i;
			while (flag[index] == -1)
			{
				flag[index] = color;
				index = ne[index];
				if (flag[index] == color)
					ans ++;
			}
		}
		
		printf( "%d\n", ans );
	}

    return 0;
}
