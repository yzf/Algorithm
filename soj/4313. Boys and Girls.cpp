#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int boy[1010], girl[1010];
int n, match[1010];                      //����ͼ���������Ϸֱ���n��m��Ԫ�ء�
bool visit[1010], map[1010][1010];               //map�洢�ڽӾ���

bool searchPath(int u) {
	for (int i = 0; i < n; i ++) {
		if (map[u][i] && !visit[i]) {
			visit[i] = true;
			int t = match[i];         //�洢match[i]��ֵ 
			match[i] = u;         //·��ȡ������
			if (t == -1 || searchPath(t)) {//Ѱ���Ƿ�Ϊ����·��
				return true;
			}
			match[i] = t;         //��ԭ 
		}
	}
	return false;
}

int maxMatch() {
	int ret = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i ++) {  //�Զ��ּ��еĽ�С��Ϊn����ƥ�����
		memset(visit, false, sizeof(visit));
		if (searchPath(i)) {
			ret ++;        //retΪƥ����
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
		/*���ݹ�ϵ�����ڽӾ���*/
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
