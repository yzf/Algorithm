#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 310;
int n, m;
int fa, score[MAX];
int son[MAX], bro[MAX];
int dp[MAX][MAX];
int result;

/*
dp[i][j] = max(tmp1, tmp2)
tmp1 = max( dp[ son[i] ][k] + dp[ bro[i] ][j - 1 - k] + score[i]) ѡi
0 <= k < j; 
tmp2 = max( dp[ bro[i] ][j] )��ѡi 
*/
/*����������ֵܽ���*/
void makeNode(int id, int fa) {
	bro[id] = son[fa];
	son[fa] = id;
}

int dfs(int i, int j) {
	if (i < 0) return 0;
	if (j <= 0)	return 0;
	if (dp[i][j] != -1)	return dp[i][j];
	//ѡi
	int tmp1 = score[i];
	int tmp = 0;
	for (int k = j - 1; k >= 0; k --) // ��������ѡk�ƣ����ֵ����ѡj-1-k��
		tmp = max( tmp, dfs(son[i], k) + dfs(bro[i], j - 1 - k) );
	tmp1 += tmp;
	//��ѡi ����ѡ����ӣ����ֵ����ѡj��
	int tmp2 = dfs(bro[i], j);
	dp[i][j] = max( tmp1, tmp2 );
	
	return dp[i][j];
}

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	memset(son, -1, sizeof(son));
	memset(bro, -1, sizeof(bro));
	memset(dp, -1, sizeof(dp));
	scanf( "%d%d", &n, &m );
	for (int i = 1; i <= n; i ++) {
		scanf( "%d%d", &fa, &score[i] );
		makeNode(i, fa);
	}

	result = dfs(0, m + 1);
	printf( "%d\n", result );

    return 0;
}                                 