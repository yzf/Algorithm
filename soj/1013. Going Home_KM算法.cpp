#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//二分图的最小权匹配 
const int MAX = 101;
const int OO = 100000000;
int n, m;
int cn1, cn2;
char str[MAX];
struct MyPoint {
	int r, c;
} h[MAX], man[MAX];

int weight[MAX][MAX];
int lx[MAX], ly[MAX];
bool sx[MAX], sy[MAX];
int match[MAX];

int abs(int num)
{
	return num > 0 ? num : -num;
}

bool dfs(int u)
{
	sx[u] = true;
	for (int v = 0; v < cn2; v ++) {
		if (!sy[v] && lx[u] + ly[v] == weight[u][v]) {
			sy[v] = true;
			if (match[v] == - 1 || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int km()
{
	for (int i = 0; i < MAX; i ++) {
		lx[i] = -OO;
		ly[i] = 0;
		for (int j = 0; j < MAX; j++) {
			if (lx[i] < weight[i][j]) {
				lx[i] = weight[i][j];
			}
		}
	}

	memset(match, -1, sizeof(match));
	for (int i = 0; i < cn1; i ++) {
		while (true) {
			memset(sx, false, sizeof(sx));
			memset(sy, false, sizeof(sy));

			if (dfs(i)) {
				break;
			}

			int slack = OO;
			for (int j = 0; j < cn1; j ++) {
				if (sx[j]) {
					for (int k = 0; k < cn2; k ++) {
						if (!sy[k]) {
							slack = min(slack, lx[j] + ly[k] - weight[j][k]);
						}
					}
				}
			}

			for (int j = 0; j < cn1; j ++) {
				if (sx[j]) {
					lx[j] -= slack;
				}
				if (sy[j]) {
					ly[j] += slack;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < cn1; i ++) {
		sum += weight[ match[i] ][i];
	}
	return -sum;
}

int main()  
{  
    //freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	while (scanf( "%d%d", &n, &m ) && n) {
		cn1 = cn2 = 0;
		for (int i = 0; i < n; i ++) {
			scanf( "%s", str );
			for (int j = 0; j < m; j ++) {
				if (str[j] == 'H') {
					h[cn1].r = i;
					h[cn1].c = j;
					cn1 ++;
				}
				if (str[j] == 'm') {
					man[cn2].r = i;
					man[cn2].c = j;
					cn2 ++;
				}
			}
		}

		for (int i = 0; i < cn1; i ++) {
			for (int j = 0; j < cn2; j ++) {
				weight[i][j] = -(abs(h[i].r - man[j].r)+abs(h[i].c - man[j].c));
			}
		}
		printf( "%d\n", km() );
	}

    return 0;  
} 
