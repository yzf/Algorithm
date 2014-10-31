#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//把问题转化为找出可能是情侣的最大对数，则N-MAX就是答案。 
const int MAX = 510;
int cases, n, Mx[MAX], My[MAX], pre[MAX], que[MAX], chk[MAX];
bool isCouple[MAX][MAX];
struct {
	int height;
	char sex;
	string style;
	string sport;
} stu[MAX];

int abs(int a, int b)
{
	if (a > b)	return a - b;
	return b - a;
}

bool coupleHeight(int dif)
{
	if (dif >= 0 && dif <= 40)	return true;
	return false;
}

int maxMatch()
{
	int ret = 0;
	int qs, qe;
	memset(Mx, -1, sizeof(Mx));
	memset(My, -1, sizeof(My));
	memset(chk, -1, sizeof(chk));
	for (int i = 0; i < n; i ++) {
		if (Mx[i] == -1) {
			qs = qe = 0;
			que[qe ++] = i;
			pre[i] = -1;
			bool flag = false;
			while (qs < qe && !flag) {
				int u = que[qs];
				for (int v = 0; v < n && !flag; v ++) {
					if (isCouple[u][v] && chk[v] != i) {
						chk[v] = i;
						que[qe ++] = My[v];
						if (My[v] >= 0)
							pre[My[v]] = u;
						else {
							flag = true;
							int d = u;
							int e = v;
							while (d != -1) {
								int t = Mx[d];
								Mx[d] = e;
								My[e] = d;
								d = pre[d];
								e = t;
							}
						}
					}
				}
				qs ++;
			}
			if (Mx[i] != -1)
				ret ++;
		}
	}
	return ret / 2;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
 
	cin >> cases;
	while (cases --) {
		memset(isCouple, false, sizeof(isCouple));
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> stu[i].height >> stu[i].sex >> stu[i].style >> stu[i].sport;
		}
		for (int i = 0; i < n-1; i ++) {
			for (int j = i+1; j < n; j ++) {
				if (coupleHeight(abs(stu[i].height, stu[j].height)) 
					&& stu[i].sex != stu[j].sex
					&& stu[i].style == stu[j].style
					&& stu[i].sport != stu[j].sport)
					isCouple[i][j] = isCouple[j][i] = true;
			}
		}
		cout << n - maxMatch() << endl;
	}

	return 0;
}
