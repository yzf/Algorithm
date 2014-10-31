#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int cases, n, a, b;
struct Ball {
	int num, weight;
	friend bool operator < (const Ball &a, const Ball &b)
	{
		return a.weight < b.weight;
	}
} ;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf( "%d", &cases );
	while (cases --)
	{
		priority_queue<Ball> Q;
		Ball ball;
		scanf( "%d", &n );
		while (n --)
		{
			scanf( "%d%d", &a, &b );
			while (a --)
			{
				scanf( "%d%d", &ball.num, &ball.weight );
				Q.push(ball);
			}
			while (b --)
				Q.pop();
		}
		printf( "%d %d\n", Q.top().num, Q.top().weight );
	}
	
    return 0;    
}
