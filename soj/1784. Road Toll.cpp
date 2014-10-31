#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 110;
int t, n, a, b;
double matric[MAX][MAX];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	int i, j, k;
	scanf( "%d", &t );
	while (t --) {
		scanf( "%d%d%d", &n, &a, &b );
		for (i = 1; i <= n; i ++) {
			for (j = 1; j <= n; j ++) {
				scanf( "%lf", &matric[i][j] );
				matric[i][j] = 1.0 - matric[i][j];
			}
		}
		//修改一下Flord算法就行了
		for (k = 1; k <= n; k ++) {
			for (i = 1; i <= n; i ++) {
				for (j = 1; j <= n; j ++) {
					matric[i][j] = max(matric[i][j], matric[i][k] * matric[k][j]);
				}
			}
		}

		printf( "%.2lf\n", matric[a][b] );
	}
	
	return 0;
}
