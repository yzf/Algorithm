#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int cases, n, ans;
int directionX[6] = {1, -1, 0, 0, 0, 0},
	directionY[6] = {0, 0, 1, -1, 0, 0},
	directionZ[6] = {0, 0, 0, 0, 1, -1};
bool visited[102][102][102], flag[102][102][102];
struct Coordinate {
	int x, y, z;
} ;
//对每个空白处使用bfs
void bfs(int x, int y, int z)
{
	Coordinate ne, temp;
	queue< Coordinate > coordinateQueue;

	ne.x = x;	ne.y = y;	ne.z = z;
	coordinateQueue.push(ne);
	visited[x][y][z] = true;
	while (!coordinateQueue.empty())
	{
		ne = coordinateQueue.front();
		coordinateQueue.pop();

		for (int i = 0; i < 6; i ++)
		{
			temp.x = ne.x + directionX[i];
			temp.y = ne.y + directionY[i];
			temp.z = ne.z + directionZ[i];

			if (temp.x >= 0 && temp.x <= 101 &&
				temp.y >= 0 && temp.y <= 101 &&
				temp.z >= 0 && temp.z <= 101 &&
				!visited[temp.x][temp.y][temp.z] && !flag[temp.x][temp.y][temp.z])
			{
				coordinateQueue.push(temp);
				visited[temp.x][temp.y][temp.z] = true;
			}
		}
	}
}      

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		int x, y, z;
		memset(visited, false, sizeof(visited));
		memset(flag, false, sizeof(flag));

		scanf( "%d", &n );
		while (n --)
		{
			scanf( "%d%d%d", &x, &y, &z );
			flag[x][y][z] = true;
		}

		ans = 0;
		for (int i = 1; i <= 100; i ++)
			for (int j = 1; j <= 100; j ++)
				for (int k = 1; k <= 100; k ++)
					if (!visited[i][j][k] && !flag[i][j][k])
					{
						bfs(i, j, k);
						ans ++;
					}
		
		printf( "%d\n", ans - 1 );
	}

    return 0;
}

