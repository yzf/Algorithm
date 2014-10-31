#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool visited[10][10];
int cases, movex[8] = {1, 2, 2, 1, -1, -2, -2, -1},
		   movey[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
char be[5], en[5];
struct State {
	int x, y;
	int step;
	bool toTarget(State &target)
	{
		return (x == target.x && y == target.y);
	}
	bool isValid()
	{
		return (x > 0 && x <= 8 && y > 0 && y <= 8);
	}
	State() 
	{	
		x = y = step = 0;	
	}
	State(int x, int y)
	{
		this->x = x;	this->y = y;	step = 0;
	}
} state, target, temp;

int getDigit(char &c)
{
	switch(c) {
	case '1':	case 'a':	return 1;		case '2':	case 'b':	return 2;
	case '3':	case 'c':	return 3;		case '4':	case 'd':	return 4;
	case '5':	case 'e':	return 5;		case '6':	case 'f':	return 6;
	case '7':	case 'g':	return 7;		case '8':	case 'h':	return 8;
	}
}

void bfs()
{
	queue<State> Q;
	Q.push(state);
	visited[state.x][state.y] = true;
	while (!Q.empty())
	{
		state = Q.front();		Q.pop();
		if (state.toTarget(target))
		{
			printf( "To get from %s to %s takes %d knight moves.\n", be, en, state.step );
			return ;
		}
		for (int i = 0; i < 8; i ++)
		{
			temp.x = state.x + movex[i];
			temp.y = state.y + movey[i];
			temp.step = state.step + 1;
			
			if (temp.isValid() && !visited[temp.x][temp.y])
			{
				visited[temp.x][temp.y] = true;
				Q.push(temp);
			}
		}
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --)
	{
		memset(visited, false, sizeof(visited));
		scanf( "%s%s", be, en );
		
		state = State(getDigit(be[1]), getDigit(be[0]));
		target = State(getDigit(en[1]), getDigit(en[0]));

		bfs();
	}

	return 0;
}
