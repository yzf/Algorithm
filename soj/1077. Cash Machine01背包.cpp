#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100001;
int cash, N, n, d, ans;
bool flag[MAX];
//用01背包做，效率低，不过10S，能过。。。
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &cash ) != EOF)
	{
		flag[0] = true;
		for (int i = 1; i <= cash; i ++)
			flag[i] = false;
		
		scanf( "%d", &N );
		while (N --)
		{
			scanf( "%d%d", &n, &d );
			while (n --)
				for (int i = cash; i >= d; i --)
					if (flag[i-d])
						flag[i] = true;
		}
		for (int i = cash; i >= 0; i --)
			if (flag[i])
			{
				ans = i;
				break;
			}
		printf( "%d\n", ans );
	}

    return 0;
}
