#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 6010;
int n, l, k;
int r[MAX], son[MAX], bro[MAX];
int root;
bool isNotRoot[MAX];
int result = 0;
int dp[MAX][2];

void makeNode(int id, int fa) {
	int preSon = son[fa];
	bro[id] = preSon;
	son[fa] = id;
}
/*
dp[i][0] = sum( max(dp[j][0], dp[j][1]) ); 
dp[i][1] = sum( dp[j][0] ) + happy[i]; 
j为i的下属
*/
int dfs(int id, int flag) {//flag = 1表示 id去
	if (dp[id][flag] != -1)	/*防止重复计算*/
		return dp[id][flag];
	dp[id][flag] = 0;
	if (flag == 1) {//id去，下属不能去
		dp[id][flag] += r[id];
		if (son[id] != 0) {
			int s = son[id];
			do {	
				dp[id][flag] += dfs(s, 0);
				s = bro[s];
			} while (s != 0);
		}
	}
	else {//id不去，下属可去可不去
		if (son[id] != 0) {
			int s = son[id];
			do {
				dp[id][flag] += max( dfs(s, 0), dfs(s, 1) );
				s = bro[s];
			} while (s != 0);
		}
	}
	return dp[id][flag];
}

int main() {
    //freopen( "input.txt", "r", stdin );
   // freopen( "output.txt", "w", stdout );
	
	memset(dp, -1, sizeof(dp));
	scanf( "%d", &n );
	for (int i = 1; i <= n; i ++) 
		scanf( "%d", &r[i] );
	for (int i = 1; i <= n; i ++) {
		scanf( "%d%d", &l, &k );
		isNotRoot[l] = true;
		makeNode(l, k);
	}
	for (int i = 1; i <= n; i ++) if (!isNotRoot[i]) {
		root = i;
		break;
	}
	dp[root][0] = dfs(root, 0);
	dp[root][1] = dfs(root, 1);
	result = max(dp[root][0], dp[root][1]);

	printf( "%d\n", result );

    return 0;
}                                 