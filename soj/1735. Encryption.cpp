#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int x[101], a[11][11];
int y[200];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d%d", &n, &m ) != EOF) {
		memset(x, 0, sizeof(x));
		int i, j, k, l, be, mark;
		for (i = 0; i < n; i ++) {
			scanf( "%d", &x[i] );
		}
		for (i = 0; i < m; i ++) {
			for (j = 0; j < m; j ++) {
				scanf( "%d", &a[i][j] );
			}
		}

		for (k = 1; ; k ++) {
			if (k * m >= n) {
				break;
			}
		}
		l = k * m;
		for (i = 0, j = 0, mark = 0; i < l; i ++) {
			y[i] = 0;
			for (k = 0, be = mark; k < m; k ++, be ++) {
				y[i] += x[be] * a[j][k];
			}
			if (++ j == m) {
				j = 0;
				mark += m;
			}
		}

		for (i = 0; i < l - 1; i ++) {
			printf( "%d ", y[i] );
		}
		printf( "%d\n", y[l - 1] );
	}

	return 0;
}
