#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n, x, y, score;

int scoreBig(int x, int y)
{
	int temp = (x - 30)*(x - 30) + (y - 30)*(y - 30);
	if (temp < 400)
		return 1;
	return 0;
}

int scoreMiddle(int x, int y)
{
	int temp = (x - 100)*(x - 100) + (y - 30)*(y - 30);
	if (temp < 100)
		return 2;
	return 0;
}

int scoreSmall(int x, int y)
{
	int temp = (x - 170)*(x - 170) + (y - 30)*(y - 30);
	if (temp < 25)
		return 3;
	return 0;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		score = 0;
		scanf( "%d", &n );
		for (int i = 0; i < n; i ++)
		{
			scanf( "%d%d", &x, &y );
			if (x <= 50 && x >= 10)
				score += scoreBig(x, y);
			else if (x <= 110 && x >= 90)
				score += scoreMiddle(x, y);
			else if (x <= 175 && x >= 165)
				score += scoreSmall(x, y);
		}
		printf( "%d\n", score );
	}

    return 0;
}
