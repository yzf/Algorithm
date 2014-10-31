#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int cases, r, c;
bool flag[30][30];
char cc, ans[600];
enum Direction {UP, DOWN, LEFT, RIGHT} dir;
int ub, db, lb, rb, cnum;
int data[] = {16, 8, 4, 2, 1};

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	for (int t = 1; t <= cases; t ++) {
		scanf( "%d%d", &r, &c );
		int i, j, len;
		for (i = 0; i < r; i ++) {
			for (j = 0; j < c; j ++) {
				cin >> cc;
				flag[i][j] = cc == '1' ? true : false;
			}
		}

		cnum = r * c;
		dir = RIGHT;
		i = j = len = 0;
		ub = 1;		db = r - 1;
		lb = 0;	rb = c - 1;
		while (cnum >= 5) {
			int sum = 0;
			for (int k = 0; k < 5; k ++) {
				sum += flag[i][j] ? data[k] : 0;
				if (dir == UP) {
					if (i - 1 < ub) {
						j ++;
						ub ++;
						dir = RIGHT;
					}
					else {
						i --;
					}
				}
				else if (dir == DOWN) {
					if (i + 1 > db) {
						j --;
						db --;
						dir = LEFT;
					}
					else {
						i ++;
					}
				}
				else if (dir == LEFT) {
					if (j - 1 < lb) {
						i --;
						lb ++;
						dir = UP;
					}
					else {
						j --;
					}
				}
				else {
					if (j + 1 > rb) {
						i ++;
						rb --;
						dir = DOWN;
					}
					else {
						j ++;
					}
				}
			}

			ans[len ++] = (sum == 0 ? ' ' : 'A' + sum - 1);
			cnum -= 5;
		}
		while (ans[len - 1] == ' ') {
			len --;
		}
		ans[len] = '\0';
		printf( "%d %s\n", t, ans );
	}

    return 0;
}
