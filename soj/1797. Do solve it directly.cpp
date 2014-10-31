#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, a, b, len, x, y;
char cmd[10000];
//09����������һ�⡣����ʱ����д�ݹ顣�������������о��ܼ򵥡����� 
void Z(int a, int b)
{
	if (a <= 0 || b <= 0)
		return ;
	cmd[len ++] = 's';
	Z(a-b, b);
	cmd[len ++] = 'r';
	Z(b-a, a);
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d%d", &a, &b );

		len = 0;
		Z(a, b);
		
		x = 0;	y = 0;
		int direction = 0;//0��ʾ+y 1��ʾ+x 2��ʾ-y 3��ʾ-x
		for (int i = 0; i < len; i ++)
		{
			if (cmd[i] == 'r')
				direction = (direction+1) % 4;
			else
			{
				switch(direction) {
				case(0) :	y ++;	break;
				case(1) :	x ++;	break;
				case(2) :	y --;	break;
				case(3) :	x --;	break;
				}
			}
		}
		printf( "%d %d\n", x, y );
	}

    return 0;
}

