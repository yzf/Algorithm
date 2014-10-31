#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 1 << 30;
const int MAX = 515;
int n;
int weight[MAX][MAX];
int cn, w[MAX * MAX];
struct Person {
	int height, age;
} men[MAX], women[MAX];

int match[MAX];
bool visit[MAX];
int ans;

bool searchPath(int u, int p)
{
	for (int i = 0; i < n; i ++) {
		if (weight[u][i] <= p && !visit[i]) {
			visit[i] = true;
			int t = match[i];
			match[i] = u;
			if (t == -1 || searchPath(t, p)) {
				return true;
			}
			match[i] = t;
		}
	}
	return false;
}

int maxMatch(int p)
{
	int ret = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i ++) {
		memset(visit, false, sizeof(visit));
		if (searchPath(i, p)) {
			ret ++;
		}
	}
	return ret;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &n ) && n) {
		int i, j;
		for (i = 0; i < n; i ++) {
			scanf( "%d%d", &men[i].height, &men[i].age );
		}
		for (i = 0; i < n; i ++) {
			scanf( "%d%d", &women[i].height, &women[i].age );
		}
		
		cn = 0;
		for (i = 0; i < n; i ++) {
			for (j = 0; j < n; j ++) {
				weight[i][j] = (men[i].height - women[j].height) * (men[i].height - women[j].height);
				weight[i][j] += (men[i].age - women[j].age) * (men[i].age - women[j].age);
				w[cn ++] = weight[i][j];
			}
		}
		
		sort(w, w + cn); 
		int low = 0, high = cn - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int temp = maxMatch(w[mid]);
			if (temp == n) {
				ans = w[mid];
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
