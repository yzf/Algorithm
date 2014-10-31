#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, items, capacity, weight, ans;
bool flag[10010];//标记该容量是否装有东西

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d%d", &items, &capacity );
		memset(flag, false, sizeof(flag));
		flag[0] = true;

		while (items --)
		{
			scanf( "%d", &weight );
			for (int i = capacity; i >= weight ; i --)
				if (flag[i-weight])
					flag[i] = true;
		}

		for (int i = capacity; i >= 0; i --)
			if (flag[i])
			{
				ans = i;
				break;
			}

		printf( "%d\n", ans );
	}

    return 0;
}
