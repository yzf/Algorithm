#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int cases, n, temp;

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d", &n );
		queue<int> card;
		if (n == 1)
		{
			printf( "1\n" );
			continue;
		}
		for (int i = 1; i <= n; i ++)
			card.push(i);

		printf( "%d ", card.front() );
		card.pop();
		temp = card.front();
		card.pop();
		card.push(temp);
		while (card.size() > 1)
		{
			printf( "%d ", card.front() );
			card.pop();
			temp = card.front();
			card.pop();
			card.push(temp);
		}
		printf( "%d \n", card.front() );
	}
	
    return 0;
}
