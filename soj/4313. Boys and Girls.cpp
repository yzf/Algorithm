#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int boy[1010], girl[1010];
int n, match[1010];                      //二分图的两个集合分别含有n和m个元素。
bool visit[1010], map[1010][1010];               //map存储邻接矩阵。

bool searchPath(int u) {
	for (int i = 0; i < n; i ++) {
		if (map[u][i] && !visit[i]) {
			visit[i] = true;
			int t = match[i];         //存储match[i]的值 
			match[i] = u;         //路径取反操作
			if (t == -1 || searchPath(t)) {//寻找是否为增广路径
				return true;
			}
			match[i] = t;         //还原 
		}
	}
	return false;
}

int maxMatch() {
	int ret = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i ++) {  //以二分集中的较小集为n进行匹配较优
		memset(visit, false, sizeof(visit));
		if (searchPath(i)) {
			ret ++;        //ret为匹配数
		}
	}
	return ret;
}

int abs(int num) {
	return num > 0 ? num : -num;
}
int main() {
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%d", &boy[i]);
		}
		for (int i = 0; i < n; i ++) {
			scanf("%d", &girl[i]);
		}
		/*根据关系生成邻接矩阵*/
		memset(map, false, sizeof(map));
		for (int i = 0; i < n; i ++) {
			int tmp = abs(boy[i]);
			if (boy[i] > 0) {
				for (int j = 0; j < n; j ++) {
					if (abs(girl[j]) > tmp) {
						map[i][j] = true;
					}
				}
			}
			else {
				for (int j = 0; j < n; j ++) {
					if (abs(girl[j]) < tmp) {
						map[i][j] = true;
					}
				}
			}
		}
		for (int i = 0; i < n; i ++) {
			int tmp = abs(girl[i]);
			if (girl[i] > 0) {
				for (int j = 0; j < n; j ++) {
					if (abs(boy[j]) <= tmp) {
						map[j][i] = false;
					}
				}
			}
			else {
				for (int j = 0; j < n; j ++) {
					if (abs(boy[j]) >= tmp) {
						map[j][i] = false;
					}
				}
			}
		}

		printf("%d\n", maxMatch());
	}

	return 0;
}
