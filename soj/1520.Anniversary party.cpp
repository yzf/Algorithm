#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 6100;
int n, a, b;
struct MyNode {
	int father, son, brother;
	int go, notGo;
} myNode[MAX];

void dfs(int nodeId)
{
	int son = myNode[nodeId].son;
	while (son != 0) {
		dfs(son);
		myNode[nodeId].go += myNode[son].notGo;//���ýڵ�ȥ��������Ӳ�ȥ
		myNode[nodeId].notGo += max(myNode[son].go, myNode[son].notGo);//���ýڵ㲻ȥ������ӿ�ȥ�ɲ�ȥ
		son = myNode[son].brother;
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF) {
		for (int i = 1; i <= n; i ++) {
			scanf( "%d", &myNode[i].go );
			myNode[i].father = myNode[i].son = myNode[i].brother = myNode[i].notGo = 0;
		}

		while (scanf( "%d%d", &a, &b ), a+b) {
			myNode[a].father = b;
			myNode[a].brother = myNode[b].son;
			myNode[b].son = a;
		}

		for (int i = 1; i <= n; i ++) {
			if (myNode[i].father == 0) {
				dfs(i);
				printf( "%d\n", max(myNode[i].go, myNode[i].notGo) );
				break;
			}
		}
	}

    return 0;
}
