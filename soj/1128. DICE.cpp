#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
//使用宽搜把所有左右型都标记好（右用true,左用false)，然后直接输出结果
int order;
bool flag[666666], handedness[666666];
queue<int> dieQue;
//有3种旋转方式
int transform1(int pre)
{
	int temp1 = pre / 100000,
		temp2 = (pre / 10000) % 10,
		temp3 = (pre / 1000) % 10,
		temp4 = (pre / 100) % 10;
	int no = (pre%100) + temp1*100 + temp2*1000 + temp3*100000 + temp4*10000;
	return no;
}

int transform2(int pre)
{
	int temp3 = (pre / 1000) % 10,
		temp4 = (pre / 100) % 10,
		temp5 = (pre / 10) % 10,
		temp6 = pre % 10;
	int no = pre/10000*10000 + temp3*10 + temp4 + temp5*100 + temp6*1000;
	return no;
}

int transform3(int pre)
{
	int temp1 = pre / 100000,
		temp2 = (pre / 10000) % 10,
		temp5 = (pre / 10) % 10,
		temp6 = pre % 10;
	int no = (pre/100%100)*100 + temp1 + temp2*10 + temp5*100000 + temp6*10000;
	return no;
}

void makeIt(bool ff)
{
	while (!dieQue.empty())
	{
		int no = dieQue.front(), ne;
		dieQue.pop();

		ne = transform1(no);
		if (!flag[ne])
		{
			dieQue.push(ne);
			flag[ne] = true;
			handedness[ne] = ff;
		}

		ne = transform2(no);
		if (!flag[ne])
		{
			dieQue.push(ne);
			flag[ne] = true;
			handedness[ne] = ff;
		}

		ne = transform3(no);
		if (!flag[ne])
		{
			dieQue.push(ne);
			flag[ne] = true;
			handedness[ne] = ff;
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	memset(flag, false, sizeof(flag));
	dieQue.push(162534);
	flag[162534] = true;
	handedness[162534] = true;
	makeIt(true);

	memset(flag, false, sizeof(flag));
	dieQue.push(162543);
	flag[162543] = true;
	handedness[162543] = false;
	makeIt(false);

	while (scanf( "%d", &order) != EOF)
	{
		if (handedness[order])
			printf( "right\n" );
		else
			printf( "left\n" );
	}

    return 0 ;
}
