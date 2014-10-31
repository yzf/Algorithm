#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int oo = 1 << 30;
const int MAX = 110;
int k;
int matric[MAX][MAX];
int n, a[MAX], m, b[MAX];
int ans, low, high;
int match[MAX];
bool visited[MAX];
//匈牙利算法
bool searchPath(int u, int p) 
{
	int i;
	for (i = 0; i < m; i ++) {
		if (matric[u][ b[i] ] <= p && !visited[ b[i] ]) {
			visited[ b[i] ] = true;
			int t = match[ b[i] ];
			match[ b[i] ] = u;
			if (t == -1 || searchPath(t, p)) {
				return true;
			}
			match[ b[i] ] = t;
		}
	}
	return false;
}

int maxMatch(int p) 
{
	int i;
	int ret = 0;
	memset(match, -1, sizeof(match));
	for (i = 0; i < n; i ++) {
		memset(visited, false, sizeof(visited));
		if (searchPath(a[i], p)) {
			ret ++;
		}
	}
	return ret;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &k ) && k) {

		int i, j, l;
		for (i = 1; i <= k; i ++) {
			for (j = 1; j <= k; j ++) {
				scanf( "%d", &matric[i][j] );
			}
		}

		scanf( "%d", &n );
		for (i = 0; i < n; i ++) {
			scanf( "%d", &a[i] );
		}
		scanf( "%d", &m );
		for (i = 0; i < m; i ++) {
			scanf( "%d", &b[i] );
		}
		//Floyd算法
		for (l = 1; l <= k; l ++) {
			for (i = 1; i <= k; i ++) {
				for (j = 1; j <= k; j ++) {
					matric[i][j] = min(matric[i][l] + matric[l][j], matric[i][j]);
				}
			}
		}
		//二分答案
		low = 1;	high = 100;		ans = 100;
		while (low <= high) {
			int mid = (low + high) / 2;
			int cn = maxMatch(mid);
			if (cn == m) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		printf( "%d\n", ans );
	}
	
	return 0;
}
