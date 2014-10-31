#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 45;
int cases, k, ba[MAX], ans[MAX];
//....... 21 13 8 5 3 2 1   各个位的权重，推出这个规律，问题就简单了 
int main()
{  
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
   
	ba[0] = 1;	ba[1] = 2;
	for (int i = 2; i < MAX; i ++)
		ba[i] = ba[i-1] + ba[i-2];

	scanf( "%d", &cases );
	while (cases --)
	{
		memset(ans, 0, sizeof(ans));
		scanf( "%d", &k );

		int highBit = MAX-1;
		while (k > 0)
		{
			for (int i = highBit; i >= 0; i --)
			{
				if (k >= ba[i])
				{
					k -= ba[i];
					ans[i] = 1;
					highBit = i-1;
					break;
				}
			}
		}

		bool flag = false;
		for (int i = MAX-1; i >= 0; i --)
		{
			if (ans[i] != 0)
				flag = true;
			if (flag)
				printf( "%d", ans[i] );
		}
		printf( "\n" );
	}

    return 0;  
} 
