#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
//两次BFS，第一次标记各个位置中毒时间，第二次看能否在逃出洞穴
const int MAX = 1000;
int m, n, tx, ty;
char c;
bool flag;
bool visited1[MAX][MAX], visited2[MAX][MAX];
int dtime[MAX][MAX];
struct Point {
	int x, y, t;
	Point(int xx = -1, int yy = -1, int tt = -1) : x(xx), y(yy), t(tt) {}
} point;

bool isValid(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n) {
		return false;
	}
	return true;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	while (cin >> m >> n && m) {
		memset(dtime, 0, sizeof(dtime));
		queue<Point > dque;
		queue<Point > pque;
		int i, j;
		for (i = 0; i < m; i ++) {
			for (j = 0; j < n; j ++) {
				cin >> c;
				if (c == 'X') {
					visited1[i][j] = true;
					visited2[i][j] = true;
				}
				else if (c == '.') {
					visited1[i][j] = false;
					visited2[i][j] = false;
				}
				else if (c == 'E') {
					tx = i;	
					ty = j;
					visited1[i][j] = false;
					visited2[i][j] = false;
				}
				else if (c == 'D') {
					dque.push(Point(i, j, 0));
					visited2[i][j] = true;
				}
				else {
					pque.push(Point(i, j, 0));
					visited1[i][j] = true;
				}
			}
		}
		
		while (!dque.empty()) {
			point = dque.front();
			dque.pop();

			for (i = -1; i <= 1; i ++) {
				for (j = -1; j <= 1; j ++) {
					if (i + j == 1 || i + j == -1) {
						int xx = point.x + i, yy = point.y + j, tt = point.t + 1;
						if (isValid(xx, yy) && !visited2[xx][yy]) {
							visited2[xx][yy] = true;
							if (xx == tx && yy == ty) {
								continue;
							}
							dtime[xx][yy] = tt;
							dque.push(Point(xx, yy, tt));
						}
					}
				}
			}
		}
		
		flag = false;
		while (!pque.empty()) {
			point = pque.front();
			pque.pop();

			for (i = -1; i <= 1; i ++) {
				if (flag) {
					break;
				}
				for (j = -1; j <= 1; j ++) {
					if (flag) {
						break;
					}
					if (i + j == 1 || i + j == -1) {
						int xx = point.x + i, yy = point.y + j, tt = point.t + 1;
						if (isValid(xx, yy) && !visited1[xx][yy]) {
							visited1[xx][yy] = true;
							if (xx == tx && yy == ty) {
								flag = true;
								printf( "%d\n", tt );
								break;
							}
							if (dtime[xx][yy] <= tt) {
								continue;
							}
							pque.push(Point(xx, yy, tt));
						}
					}
				}
			}
		}
		if (!flag) {
			printf( "YYR is extremely dangerous!\n" );
		}
	}

	return 0;
}
