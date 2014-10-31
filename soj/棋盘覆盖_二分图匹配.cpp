#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
/*把每个格子染成黑色和白色，其中相邻格子颜色不同，则每个覆盖包含有一个黑色和一个白色
这样，可以把问题转化为二分图匹配*/
const int MAX = 10010;
int n, match[MAX];                     
bool visit[MAX];
bool isDelete[110][110];

int s, m;
int a, b;
int dirR[4] = {0, -1, 0, 1};
int dirC[4] = {-1, 0, 1, 0};
/*把坐标变成一维*/
int myMap(int r, int c) {
	return r * s + c;
}
/*获取一维数的横*/
int getRow(int num) {
	return num / s;
}
/*获取一维数的列*/
int getCol(int num) {
	return num % s;
}
/*判断该位置是否有效*/
bool isValid(int r, int c) {
	if (r < 0 || r >= s || c < 0 || c >= s) {
		return false;
	}
	if (isDelete[r][c]) {
		return false;
	}
	return true;
}

bool searchPath(int u) {
	int r = getRow(u);
	int c = getCol(u);
	for (int i = 0; i < 4; i ++) {
		int adjR = r + dirR[i];
		int adjC = c + dirC[i];
		int v = myMap(adjR, adjC);
		if (isValid(adjR, adjC) && !visit[v]) {
			visit[v] = true;
			int t = match[v];         
			match[v] = u;        
			if (t == -1 || searchPath(t)) {
				return true;
			}
			match[v] = t;         
		}
	}
	return false;
}

int maxMatch() {
	int ret = 0;
	memset(match, -1, sizeof(match));
	/*染色，把与0同色的放进oneSide*/
	vector<int> oneSide;
	if (s % 2 == 0) {
		for (int i = 0; i < s; i ++) {
			if (i % 2 == 0) 
				for (int j = 0; j < s; j += 2) 
					oneSide.push_back(myMap(i, j));
			else 
				for (int j = 1; j < s; j += 2) 
					oneSide.push_back(myMap(i, j));
		}
	}
	else 
		for (int i = 0; i < n; i += 2)		
			oneSide.push_back(i);
	/*匈牙利算法*/
	for (int i = 0; i < oneSide.size(); i ++) {
		int u = oneSide[i];
		if (!isDelete[ getRow(u) ][ getCol(u) ]) {
			memset(visit, false, n * sizeof(bool));
			if (searchPath(u)) {
				ret ++;       
			}
		}
	}
	return ret;
}

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf("%d%d", &s, &m);
	fprintf(stderr, "%d %d\n", s, m);
	for (int i = 0; i < m; i ++) {
		scanf("%d%d", &a, &b);
		a --;
		b --;
		fprintf(stderr, "%d %d\n", a, b);
		isDelete[a][b] = true;
	}
	n = s * s;
	printf("%d\n", maxMatch());

    return 0;
}                                 