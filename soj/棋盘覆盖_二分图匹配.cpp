#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
/*��ÿ������Ⱦ�ɺ�ɫ�Ͱ�ɫ���������ڸ�����ɫ��ͬ����ÿ�����ǰ�����һ����ɫ��һ����ɫ
���������԰�����ת��Ϊ����ͼƥ��*/
const int MAX = 10010;
int n, match[MAX];                     
bool visit[MAX];
bool isDelete[110][110];

int s, m;
int a, b;
int dirR[4] = {0, -1, 0, 1};
int dirC[4] = {-1, 0, 1, 0};
/*��������һά*/
int myMap(int r, int c) {
	return r * s + c;
}
/*��ȡһά���ĺ�*/
int getRow(int num) {
	return num / s;
}
/*��ȡһά������*/
int getCol(int num) {
	return num % s;
}
/*�жϸ�λ���Ƿ���Ч*/
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
	/*Ⱦɫ������0ͬɫ�ķŽ�oneSide*/
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
	/*�������㷨*/
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