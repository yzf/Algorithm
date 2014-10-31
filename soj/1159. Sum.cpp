#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXNUM = 110;

int n, sum[MAXNUM], add[MAXNUM];
char str[MAXNUM];

void strToInt()
{
    memset(add, 0, sizeof(add));
	int i, index;
	for (i = strlen(str)-1, index = MAXNUM-1; i >= 0; i --, index --)
		add[index] = str[i] - '0';
}

void addIt()
{
	for (int i = MAXNUM-1; i >= 0; i --)
		sum[i] += add[i];
}

void getAnswer()
{
	for (int i = MAXNUM-1; i >= 1; i --)
	{
		int temp = sum[i];
		sum[i] = temp % 10;
		sum[i-1] += temp / 10;
	}
	
	bool mark = false;
	for (int i = 0; i < MAXNUM; i ++)
	{
        if (sum[i] != 0)
            mark = true;
        if (mark)
            printf( "%d", sum[i] );
    }
    printf( "\n" );
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF)
	{
		memset(sum, 0, sizeof(sum));

		for (int i = 0; i < n; i ++)
		{
			scanf( "%s", str );
		    strToInt();
		    addIt();
        }
		getAnswer();
	}

	return 0;
}
