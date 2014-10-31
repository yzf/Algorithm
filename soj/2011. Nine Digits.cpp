#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int n, target[9], b[9], a[9];
map<int, int> step;
queue<int> Q;

int getnum(int t[])
{
    int s = 0;
	for (int i = 0; i < 9; i ++)
	{
		s *= 10;
		s += t[i];
	}
    return s;
}

void getarray(int n)
{
	for (int i = 8; i >= 0; i --)
	{
		b[i] = n % 10;
		n /= 10;
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	Q.push(123456789);
	step[123456789] = 1;

	while (!Q.empty())
	{
		int no, ne;
		no = Q.front();
		Q.pop();

		getarray(no);
		int temp = b[8];	b[8] = b[7];	b[7] = b[4];	b[4] = b[5];	b[5] = temp;
		ne = getnum(b);
		if (step[ne] == 0)
		{
			Q.push(ne);
			step[ne] = step[no] + 1;
		}
		temp = b[8];	b[8] = b[5];	b[5] = b[4];	b[4] = b[7];	b[7] = temp;
		temp = b[7];	b[7] = b[6];	b[6] = b[3];	b[3] = b[4];	b[4] = temp;
		ne = getnum(b);
		if (step[ne] == 0)
		{
			Q.push(ne);
			step[ne] = step[no] + 1;
		}
		temp = b[7];	b[7] = b[4];	b[4] = b[3];	b[3] = b[6];	b[6] = temp;
		temp = b[5];	b[5] = b[4];	b[4] = b[1];	b[1] = b[2];	b[2] = temp;
		ne = getnum(b);
		if (step[ne] == 0)
		{
			Q.push(ne);
			step[ne] = step[no] + 1;
		}
		temp = b[2];	b[2] = b[1];	b[1] = b[4];	b[4] = b[5];	b[5] = temp;
		temp = b[4];	b[4] = b[3];	b[3] = b[0];	b[0] = b[1];	b[1] = temp;
		ne = getnum(b);
		if (step[ne] == 0)
		{
			Q.push(ne);
			step[ne] = step[no] + 1;
		}
	}
    
    while (scanf( "%d", &target[0]) != EOF)
    {
        for (int i = 1; i < 9; i ++)
            scanf( "%d", &target[i]);
            
		printf( "%d\n", step[ getnum(target) ]-1 );
    }
    
    return 0;
}
