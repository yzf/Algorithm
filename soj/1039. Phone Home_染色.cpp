#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 15;
int n, cases, ans;
bool adj[MAX][MAX];
struct {
	double x, y;
	int color;
} point[MAX];

bool isOk(int index, int color)//判断颜色是否符合
{
	for (int i = 0; i < n; i ++) {
		if (adj[index][i] && color == point[i].color) {
			return false;
		}
	}
	return true;
}

void dfs(int index, int colorCn)
{
	if (colorCn >= ans)	return ;
	if (index == n) {
		ans = colorCn;
		return ;
	}
	for (int i = 1; i <= colorCn; i ++) {//不增加颜色的情况下
		if (isOk(index, i)) {
			point[index].color = i;
			dfs(index+1, colorCn);
			point[index].color = 0;
		}
	}//增加颜色
	point[index].color = colorCn+1;
	dfs(index+1, colorCn+1);
	point[index].color = 0;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
 
	cases = 1;
	while (cin >> n && n != 0) {
		memset(adj, false, sizeof(adj));
		for (int i = 0; i < n; i ++) {
			cin >> point[i].x >> point[i].y;
			point[i].color = 0;
		}
		for (int i = 0; i < n-1; i ++) {
			for (int j = i+1; j < n; j ++) {
				if ((point[i].x-point[j].x)*(point[i].x-point[j].x)
					+(point[i].y-point[j].y)*(point[i].y-point[j].y) <= 400.0) {
					adj[i][j] = adj[j][i] = true;
				}
			}
		}
		ans = 15;
		dfs(0, 0);
		cout << "The towers in case " << cases ++ << " can be covered in " << ans << " frequencies.\n";
	}

	return 0;
}
