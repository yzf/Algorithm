#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	int cases;
	scanf( "%d", &cases );
	while (cases --)
	{
		int n;
		queue<int> card;

		scanf( "%d", &n );
		for (int i = 1; i <= n; i ++)
			card.push(i);

		if (n == 1)
		{
			printf( "1 \n" );
			continue;
		}

		while (true)
		{
			if (card.size() == 2)
			{
				printf( "%d ", card.front() );
				card.pop();
				printf( "%d \n", card.front() );
				card.pop();
				break;
			}
			printf( "%d ", card.front() );
			card.pop();
			int temp = card.front();
			card.pop();
			card.push(temp);
		}
	}

    return 0;
}
