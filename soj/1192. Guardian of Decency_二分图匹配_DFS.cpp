#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//把问题转化为找出可能是情侣的最大对数，则N-MAX就是答案。 
const int MAX = 510;
int cases, n, xM[MAX], yM[MAX];
bool isCouple[MAX][MAX], chk[MAX];
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

bool searchPath(int u)
{
	for (int v = 0; v < n; v ++) {
		if (isCouple[u][v] && !chk[v]) {
			chk[v] = true;
			if (yM[v] == -1 || searchPath(yM[v])) {
				yM[v] = u;	xM[u] = v;
				return true;
			}
		}
	}
	return false;
}

int maxMatch()
{
	int ret = 0;
	memset(xM, -1, n*sizeof(int));
	memset(yM, -1, n*sizeof(int));
	for (int u = 0; u < n; u ++) {
		if (xM[u] == -1) {
			memset(chk, false, n*sizeof(bool));
			if (searchPath(u)) {
				ret ++;
			}
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
