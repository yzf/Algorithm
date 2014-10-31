#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 60;
int t, r, c;
int v[MAX][MAX];
int dirr[4] = {0, -1, 0, 1}, 
	dirc[4] = {-1, 0, 1, 0};
int visited[MAX][MAX];

struct Pos {
	int r, c;
	int value;
} cur, ne;
//重载操作符，用于优先队列
bool operator < (const Pos &lhs, const Pos &rhs)
{
	return lhs.value > rhs.value;
}
//差的绝对值
int myabs(int a, int b)
{
	return a > b ? a - b : b - a;
}
//判断该位置是否已经走过
bool isValid(int a, int b)
{
	if (a < 0 || a >= r || b < 0 || b >= c)
	{
		return false;
	}
	return !visited[a][b];
}
//宽搜进行最短路搜索
int bfs()
{
	int result = 0;
	int cn = r * c;
	priority_queue<Pos> que;
	que.push(cur);
	while (!que.empty() && cn > 0)
	{
		cur = que.top();
		que.pop();
		if (!visited[cur.r][cur.c])
		{
			visited[cur.r][cur.c] = true;
			result += cur.value;
			cn --;
		}
		else //该位置已用更优的走法走过
		{
			continue;
		}
		//邻居位置入队
		for (int i = 0; i < 4; i ++)
		{
			ne.r = cur.r + dirr[i];
			ne.c = cur.c + dirc[i];
			if (isValid(ne.r, ne.c))
			{
				int tmp = myabs(v[cur.r][cur.c], v[ne.r][ne.c]);
				ne.value = tmp * tmp;
				que.push(ne);
			}
		}
	}
	return result;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> t;
	while (t --)
	{
		memset(visited, false, sizeof(visited));
		cin >> r >> c;
		for (int i = 0; i < r; i ++)
		{
			for (int j = 0; j < c; j ++)
			{
				cin >> v[i][j];
				if (v[i][j] == 0)
				{
					cur.r = i;
					cur.c = j;
					cur.value = 0;
				}
			}
		}

		cout << bfs() << endl;
	}

    return 0;
}
