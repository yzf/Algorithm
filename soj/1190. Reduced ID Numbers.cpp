#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1000010;

int t, n, answer, sins[MAX];
bool isUsed[MAX];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --)
	{
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
			scanf( "%d", &sins[i] );

		for (answer = 1; answer < MAX; answer ++)
		{
			for (int i = 0; i < answer; i ++)
				isUsed[i] = false;

			int index;
			for (index = 0; index < n; index ++)
			{
				int temp = sins[index] % answer;
				if (isUsed[temp])
					break;
				isUsed[temp] = true;
			}
			if (index == n)
				break;
		}
		printf( "%d\n", answer );
	}


    return 0;
}
