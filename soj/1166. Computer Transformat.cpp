#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int BASE = 10000;

int bigNum[1001][100];
int n;

int getDigit(int number)
{
	int digit = 0;
	if (number == 0)
		return 1;
	else while (number > 0)
	{
		number /= 10;
		digit ++;
	}
	return digit;
}

void getNext(int x, int y, int z)
{
	int temp;
	for (int i = 0; i < 99; i ++)
	{
		bigNum[x][i] = bigNum[y][i] << 1;
	}
	bigNum[x][0] += z;
	for (int i = 0; i < 99; i ++)
	{
		bigNum[x][i+1] += bigNum[x][i] / BASE;
		bigNum[x][i] = bigNum[x][i] % BASE;
	}
}

void init()
{
	bigNum[2][0] = 1;
	for (int i = 3; i <= 1000; i ++)
	{
		if (i %2 == 1)
			getNext(i, i-1, -1);
		else 
			getNext(i, i-1, 1);
	}
}

void output(int n)
{
	int be;
	for (be = 99; be >= 0; be --)
		if (bigNum[n][be] != 0)
			break;
	printf( "%d", bigNum[n][be --] );
	for (; be >= 0; be --)
	{
		for (int i = 0; i < 4-getDigit(bigNum[n][be]); i++)
			printf( "0" );
		printf( "%d", bigNum[n][be] );
	}
	printf( "\n" );
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	memset(bigNum, 0, sizeof(bigNum));

	init();

	while (scanf( "%d", &n ) != EOF)
	{
		if (n == 1)
			printf( "0\n" );
		else
			output(n);
	}

	return 0;
}
/*
��ĿҪ�� 00 �ĸ�������ʵҲ���� 1001 �ĸ����� 
01 ���ܲ��� 1001 �� ��Ҫ���� 01�������� 00��1001���� 1 ������
ע��000�ܲ���101010��������2��01��
���Ǹ�����Ŀ��ת�������ǲ����ܳ�������2��0���ϵģ�
�������ﲻ�ÿ��ǡ�1�ĸ���������Ϊ2^(n-1)��

00 (1001)  ----> 01   -----> 00 (1001)

1

��f(n)Ϊ��Ŀ����00����
0 1 1 3 5 11...
�� f(n)=f(n-2)+2^(n-3)����Ȼ�����ܻ���f(n)��f(n-1)�Ĺ�ϵʽ��
   f [n] = 2 * f [n - 1] + 1       ��n ��ż����
   f [n] = 2 * f [n - 1] - 1        ��n ��������
