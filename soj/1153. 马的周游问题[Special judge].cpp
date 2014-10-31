#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited[65];//flag标记是否完成搜索 
int nextPosition[8][2] = {2,1,2,-1,-2,1,-2,-1,1,2,1,-2,-1,2,-1,-2}; //马的8种走法 
int answer[65];

bool isValid(int x, int y)
{
	if (x < 0 || x > 7 || y < 0 || y > 7)
		return false;
	return true;
}

int countStep(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 8; i ++)
	{
		int xTemp = x + nextPosition[i][0];
		int yTemp = y + nextPosition[i][1];
		if (isValid(xTemp, yTemp) && !visited[xTemp*8+yTemp+1])
			sum ++;
	}
	return sum;
}

struct Coord {
	int x, y;
	int stepNumber;
	Coord(int x1, int y1) : x(x1), y(y1), stepNumber(countStep(x, y)) {}
} ;

bool cmp(const Coord &a, const Coord &b)
{
	return a.stepNumber < b.stepNumber;
}

bool dfs(int x, int y, int number)//搜索路线 
{
	vector<Coord> point;
	visited[x*8+y+1] = true;
	answer[number] = x*8+y+1;

	if (number == 63)
		return true;
	for (int i = 0; i < 8; i ++)
	{
		int xTemp = x + nextPosition[i][0];
		int yTemp = y + nextPosition[i][1];
		if (isValid(xTemp, yTemp) && !visited[xTemp*8+yTemp+1])
			point.push_back(Coord(xTemp, yTemp));
	}

	sort(point.begin(), point.end(), cmp);
	for (int i = 0; i < point.size(); i ++)
		if (dfs(point[i].x, point[i].y, number+1))
			return true;

	visited[x*8+y+1] = false;
	return false;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    for (scanf("%d",&n); n != -1; scanf("%d",&n))
    {
        memset(visited, false, sizeof(visited));
        
		dfs((n-1)/8, (n-1)%8, 0);

		printf( "%d", answer[0] );
		for (int i = 1; i < 64; i ++)
			printf( " %d", answer[i] );
		printf( "\n" );
    }
    
    return 0;
}
