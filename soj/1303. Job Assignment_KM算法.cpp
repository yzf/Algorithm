#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 101;
const int OO = 100000000;
int n;
int weight[MAX][MAX];
int lx[MAX], ly[MAX];
bool sx[MAX], sy[MAX];
int match[MAX];

bool dfs(int u)
{
	sx[u] = true;
	for (int v = 0; v < n; v ++) {
		if (!sy[v] && lx[u] + ly[v] == weight[u][v]) {
			sy[v] = true;
			if (match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int km()
{
	for (int i = 0; i < n; i ++) {
		lx[i] = -OO;
		ly[i] = 0;
		for (int j = 0; j < n; j ++) {
			if (lx[i] < weight[i][j]) {
				lx[i] = weight[i][j];
			}
		}
	}

	memset(match, -1, sizeof(match));
	for (int u = 0; u < n; u ++) {
		while (true) {
			memset(sx, false, sizeof(sx));
			memset(sy, false, sizeof(sy));

			if (dfs(u)) {
				break;
			}

			int slack = OO;
			for (int i = 0; i < n; i ++) {
				if (sx[i]) {
					for (int j = 0; j < n; j ++) {
						if (!sy[j]) {
							slack = min(slack, lx[i] + ly[j] - weight[i][j]);
						}
					}
				}
			}

			for (int i = 0; i < n; i ++) {
				if (sx[i]) {
					lx[i] -= slack;
				}
				if (sy[i]) {
					ly[i] += slack;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i ++) {
		sum += weight[ match[i] ][i];
	}
	return sum;
}

int main()  
{  
    //freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	while (scanf( "%d", &n ) && n) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				scanf( "%d", &weight[i][j] );
			}
		}
		printf( "%d\n", km() );
	}

    return 0;  
} 
