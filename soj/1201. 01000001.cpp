#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXNUM = 100;

int n;
int number1[MAXNUM], number2[MAXNUM], sum[MAXNUM];
char str1[MAXNUM], str2[MAXNUM];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	for (int i = 1; i <= n; i ++)
	{
		scanf( "%s%s", str1, str2 );
		
		memset(number1, 0, sizeof(number1));
		memset(number2, 0, sizeof(number2));
    	memset(sum, 0, sizeof(sum));
    	
		for (int i = strlen(str1)-1, j = MAXNUM-1; i >= 0; i --, j --)
			number1[j] = str1[i] - '0';
		for (int i = strlen(str2)-1, j = MAXNUM-1; i >= 0; i --, j --)
			number2[j] = str2[i] - '0';
		
		for (int i = MAXNUM-1; i >= 0; i --)
		{
			sum[i] += number1[i] + number2[i];
			sum[i-1] += sum[i] / 2;
			sum[i] %= 2;
		}

		printf( "%d ", i );
		bool flag = false;
		for (int i = 0; i < MAXNUM; i ++)
		{
			if (sum[i] > 0)    flag = true;
			if (flag)
				printf( "%d", sum[i] );
		}
		if (!flag)//结果为0时的处理。。。
			printf( "0" );
		printf( "\n" );
	}
	
	return 0;
}
