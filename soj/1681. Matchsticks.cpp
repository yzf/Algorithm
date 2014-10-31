#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool flag;
int cases, n, len1, minNum[100], len2, maxNum[100];
/*
最小数，尽量使用8
小于等于21，暴力
*/
void getMin()
{
	int temp = n;
	while (temp > 21)
	{
		minNum[++ len1] = 8;
		temp -= 7;
	}
	switch(temp)	{
	case 2: minNum[++ len1] = 1;	break;
	case 3:	minNum[++ len1] = 7;	break;
	case 4:	minNum[++ len1] = 4;	break;
	case 5:	minNum[++ len1] = 2;	break;
	case 6:	minNum[++ len1] = 6;	break;
	case 7:	minNum[++ len1] = 8;	break;
	case 8:	minNum[++ len1] = 10;	break;
	case 9:	minNum[++ len1] = 18;	break;
	case 10:	minNum[++ len1] = 22;	break;
	case 11:	minNum[++ len1] = 20;	break;
	case 12:	minNum[++ len1] = 28;	break;
	case 13:	minNum[++ len1] = 68;	break;
	case 14:	minNum[++ len1] = 88;	break;
	case 15:	minNum[++ len1] = 108;	break;
	case 16:	minNum[++ len1] = 188;	break;
	case 17:	minNum[++ len1] = 200;	break;
	case 18:	minNum[++ len1] = 208;	break;
	case 19:	minNum[++ len1] = 288;	break;
	case 20:	minNum[++ len1] = 688;	break;
	case 21:	minNum[++ len1] = 888;	break;
	}
}

void getMax()
{
	int temp = n;
	while (temp > 1)
	{
		maxNum[++ len2] = 1;
		temp -= 2;
	}
	if (temp == 1)
		maxNum[len2] = 7;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d", &n );

		flag = false;	len1 = -1;	len2 = -1;
		getMin();
		getMax();

		for (int i = len1; i > 0; i --)
			printf( "%d", minNum[i] );
		printf( "%d ", minNum[0] );
		for (int i = len2; i > 0; i --)
			printf( "%d", maxNum[i] );
		printf( "%d\n", maxNum[0] );
	}

	return 0;
}
