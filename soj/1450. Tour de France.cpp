#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10;
int n, m, cn;
double front[MAX], rear[MAX];
double ratio[MAX * MAX];
double ans;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	int i, j;
	while (scanf( "%d", &n ) && n) {
		scanf( "%d", &m );
		for (i = 0; i < n; i ++) {
			scanf( "%lf", &front[i] );
		}
		for (i = 0; i < m; i ++) {
			scanf( "%lf", &rear[i] );
		}

		cn = 0;
		for (i = 0; i < m; i ++) {
			for (j = 0; j < n; j ++) {
				ratio[cn ++] = rear[i] / front[j];
			}
		}
		sort(ratio, ratio+cn);

		ans = 0.0;
		for (i = 1; i < cn; i ++) {
			ans = max(ans, ratio[i] / ratio[i - 1]);
		}
		printf( "%.2lf\n", ans );
	}
	
	return 0;
}
