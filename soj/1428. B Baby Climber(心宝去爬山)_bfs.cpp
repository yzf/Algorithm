#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
//从当前最高点BFS就行了 
const int MAX = 60;
char str[MAX];
int value[MAX][MAX];
bool flag[MAX][MAX];
int n, m, i, j, k, cn, ans;
struct Point {
	int x, y;
	Point(int tx = -1, int ty = -1) : x(tx), y(ty) {}
} point[MAX * MAX], cur;
queue<Point> que;

bool cmp(const Point lhs, const Point rhs)
{
	return value[lhs.x][lhs.y] < value[rhs.x][rhs.y];
}

bool isValid(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	return true;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%s", str ) != EOF) {

		m = strlen(str);
		cn = 0;
		for (n = 1; ; n ++) {
			i = n - 1;
			for (j = 0; j < m; j ++) {
				point[cn ++] = Point(i, j);
				value[i][j] = str[j] - 'a';
			}
			scanf ( "%s", str );
			if (str[0] == '*') {
				break;
			}
		}

		sort(point, point + cn, cmp);

		memset(flag, false, sizeof(flag));
		ans = 0;
		for (i = 0; i < cn; i ++) {
			cur = point[i];
			if (!flag[ cur.x ][ cur.y ]) {

				flag[ cur.x ][ cur.y ] = true;
				que.push(cur);
				while (!que.empty()) {
					cur = que.front();
					que.pop();

					for (j = -1; j <= 1; j ++) {
						for (k = -1; k <= 1; k ++) {
							if (j + k == 1 || j + k == -1) {
								int x = cur.x + j, y = cur.y + k;
								if (isValid(x, y) && !flag[x][y] && value[x][y] >= value[cur.x][cur.y]) {
									flag[x][y] = true;
									que.push(Point(x, y));
								}
							}
						}
					}
				}

				ans ++;
			}
		}

		printf( "%d\n", ans );
	}
	
	return 0;
}
