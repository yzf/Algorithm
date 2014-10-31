#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cases;
char num[120];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%s", num );
		int len = strlen(num);
		int i, j, k;
		for (i = 0; i < len; i ++)
		{
			if (num[i] == '0')
				continue;
			k = i;
			for (j = i+1; j < len; j ++)
			{
				if (num[j] == '0')
					break;
				if (num[j] > num[k])
					k = j;
			}
			swap(num[i], num[k]);
		}
		printf( "%s\n", num );
	}

    return 0;
}
