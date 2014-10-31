#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 1 << 10;
int cases;
char state[15];
bool visited[MAX];
int ways[MAX];
bitset<9> grid;//纯粹想用用bitset
queue<int> gridQueue;

void transform(int n)
{
	switch(n) {
	case 1: grid.flip(0);	grid.flip(1);	grid.flip(3);	grid.flip(4);	break;
	case 2: grid.flip(0);	grid.flip(1);	grid.flip(2);	grid.flip(3);	grid.flip(4);	grid.flip(5);	break;
	case 3: grid.flip(1);	grid.flip(2);	grid.flip(4);	grid.flip(5);	break;
	case 4: grid.flip(0);	grid.flip(1);	grid.flip(3);	grid.flip(4);	grid.flip(6);	grid.flip(7);	break;
	case 5: grid.flip();	break;
	case 6: grid.flip(1);	grid.flip(2);	grid.flip(4);	grid.flip(5);	grid.flip(7);	grid.flip(8);	break;
	case 7: grid.flip(3);	grid.flip(4);	grid.flip(6);	grid.flip(7);	break;
	case 8: grid.flip(3);	grid.flip(4);	grid.flip(5);	grid.flip(6);	grid.flip(7);	grid.flip(8);	break;
	case 9: grid.flip(4);	grid.flip(5);	grid.flip(7);	grid.flip(8);	break;
	}
}

void search()//宽搜
{
	while (!gridQueue.empty())
	{
		for (int i = 1; i <= 9; i ++)
		{
			grid = gridQueue.front();
			transform(i);
			int temp = grid.to_ulong();
			if (!visited[temp])
			{
				ways[temp] = i;
				gridQueue.push(temp);
				visited[temp] = true;
			}
		}
		gridQueue.pop();
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	grid.set();
	gridQueue.push(grid.to_ulong());
	visited[grid.to_ulong()] = true;
	search();

	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%s", state );
		grid.set();
		for (int i = 0; i < 9; i ++)
			if (state[i] == 'b')
				grid.reset(i);

		if (grid == 511)//全白即 511 
		{
			printf( "11\n" );
			continue;
		}

		stack<int> ans;
		while (grid != 511)
		{
			int temp = ways[grid.to_ulong()];
			ans.push(temp);
			transform(temp);
		}
		while (!ans.empty())
		{
			printf( "%d", ans.top());
			ans.pop();
		}
		printf( "\n" );
	}

    return 0;
}
