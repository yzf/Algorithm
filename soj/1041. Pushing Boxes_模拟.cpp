#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int MAX = 30;
int height, width;
int n, r, c;
bool flag[MAX][MAX];//标记位置是否有箱子
int rcn[MAX], ccn[MAX];//记录某行或者某列有箱子的个数
string cmd;
int num;
//获取或者列的最大箱子数
int getMax(int *arr, int len)
{
	int result = arr[0];
	for (int i = 1; i <= len; i ++)
		if (arr[i] > result)
			result = arr[i];
	return result;
}
//操作
void solve()
{
	int move = 0, tmp = 0;
	if (cmd == "up")
	{
		move = num;
		tmp = height - getMax(ccn, width) + 1;
		if (move > tmp)
			move = tmp;
		move = height - move + 1;
		for (int i = move; i <= height; i ++)
			for (int j = 0; j <= width; j ++)
				if (flag[i][j])
				{
					flag[i][j] = false;
					rcn[i] --;
					for (int k = move - 1; k >= 0; k --)
						if (!flag[k][j])
						{
							rcn[k] ++;
							flag[k][j] = true;
							break;
						}
				}
	}
	else if (cmd == "down")
	{
		move = num;
		tmp = height - getMax(ccn, width) + 1;
		if (move > tmp)
			move = tmp;
		for (int i = 0; i < move; i ++)
			for (int j = 0; j <= width; j ++)
				if (flag[i][j])
				{
					flag[i][j] = false;
					rcn[i] --;
					for (int k = move; k <= height; k ++)
						if (!flag[k][j])
						{
							rcn[k] ++;
							flag[k][j] = true;
							break;
						}
				}
	}
	else if (cmd == "left")
	{
		move = num;
		tmp = width - getMax(rcn, height) + 1;
		if (move > tmp)
			move = tmp;
		move = width - move + 1;
		for (int i = 0; i <= height; i ++)
			for (int j = move; j <= width; j ++)
				if (flag[i][j])
				{
					flag[i][j] = false;
					ccn[j] --;
					for (int k = move - 1; k >= 0; k --)
						if (!flag[i][k])
						{
							ccn[k] ++;
							flag[i][k] = true;
							break;
						}
				}
	}
	else 
	{
		move = num;
		tmp = width - getMax(rcn, height) + 1;
		if (move > tmp)
			move = tmp;
		for (int i = 0; i <= height; i ++)
			for (int j = 0; j < move; j ++)
				if (flag[i][j])
				{
					flag[i][j] = false;
					ccn[j] --;
					for (int k = move; k <= width; k ++)
						if (!flag[i][k])
						{
							ccn[k] ++;
							flag[i][k] = true;
							break;
						}
				}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	int test = 1;
	while (cin >> height >> width)
	{
		if (height == 0 && width == 0) 
			break;
		height --;
		width --;
		memset (flag, false, sizeof(flag));
		memset (rcn, 0, sizeof(rcn));
		memset (ccn, 0, sizeof(ccn));
		cin >> n;
		for (int i = 0; i < n; i ++)
		{
			cin >> r >> c;
			flag[r][c] = true;
			rcn[r] ++;
			ccn[c] ++;
		}
		while (true)
		{
			cin >> cmd;
			if (cmd == "done")
				break;
			cin >> num;
			solve();
		}
		cout << "Data set " << test ++ << " ends with boxes at locations";
		for (int i = 0; i <= height; i ++)
			for (int j = 0; j <= width; j ++)
				if (flag[i][j])
					cout << " (" << i << "," << j << ")";
		cout << ".\n";
	}

    return 0;
}
