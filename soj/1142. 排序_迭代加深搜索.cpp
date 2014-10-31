#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 30;
int n, data[MAX], position[MAX];//position[i]表示第i个数是原来序列的第几个数。

bool cmp(const int a, const int b)
{
	return data[a] < data[b];
}

int cal()//估计函数，估计至少用多少步,用于剪枝 
{
	int result = 0;
	for (int i = 0; i < n - 1; i ++)
		if (position[i] > position[i+1]+1 || position[i+1] > position[i]+1)
			result ++;
	return result;
}

bool isSorted()//判断是否已找到答案
{
	for (int i = 0; i < n - 1; i ++)
		if (position[i] > position[i+1])
			return false;
	return true;
}

bool ids(int bound)//bound为剩余步数
{
	if (bound == 0) {
		if (isSorted())
			return true;
		else
			return false;
	}
	else if (cal() > bound)//剪枝
		return false;
	else {
		for (int i = 2; i <= n; i ++) {
			reverse(position, position+i);
			if (ids(bound - 1))
				return true;
			reverse(position, position+i);//还原
		}
		return false;
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	for (int i = 0; i < n; i ++) {
		position[i] = i;
		scanf( "%d", &data[i] );
	}
	sort(position, position+n, cmp);
	for (int i = 0; ; i ++) {
		if (ids(i)) {
			printf( "%d\n", i );
			break;
		}
	}

    return 0;
}
