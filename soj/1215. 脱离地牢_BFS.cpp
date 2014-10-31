#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool visited[25][25][25][25];
int n, m, px, py, hx, hy;
char a[25][25], pmove[10] = "NSWE", hmove[10];
//用BFS做，不过，这题很阴险，容易出错`~~ 
struct State {
	int px, py;
	int hx, hy;
	int cn;
	bool isValue()	
	{
		return px >= 0 && px < n &&  py >= 0 && py < m
			&& hx >= 0 && hx < n && hy >= 0 && hy < m ;
	}
	bool isMeet()	{	return px == hx && py == hy;}
	bool isCollision(State &s)//这种情况易漏~~~
	{
		return (px == s.hx && py == s.hy && hx == s.px && hy == s.py);
	}
} ;

void getNextPosition(char &dir1, char &dir2, State &cur)
{
	switch(dir1) {
	case 'N':	cur.px --;	break;
	case 'S':	cur.px ++;	break;
	case 'W':	cur.py --;	break;	
	case 'E':	cur.py ++;	break;
	}
	switch(dir2) {
	case 'N':	cur.hx --;	break;
	case 'S':	cur.hx ++;	break;
	case 'W':	cur.hy --;	break;	
	case 'E':	cur.hy ++;	break;
	}
	cur.cn ++;
}

void bfs()
{	
	State state, ne;
	queue<State > que;

	state.cn = 0;	state.px = px;	state.py = py;	state.hx = hx;	state.hy = hy;
	que.push(state);
	visited[state.px][state.py][state.hx][state.hy] = true;
	while (!que.empty())
	{
		state = que.front();		que.pop();
		if (state.cn > 255)
		{
			cout << "Impossible\n";
			return ;
		}

		for (int i = 0; i < 4; i ++)
		{
			ne = state;
			getNextPosition(pmove[i], hmove[i], ne);

			if (ne.isValue() && a[ne.px][ne.py] == '.' && a[ne.hx][ne.hy] != '!')
			{
				if (a[ne.hx][ne.hy] == '#')
				{
					ne.hx = state.hx;	ne.hy = state.hy;
				}
				if (!visited[ne.px][ne.py][ne.hx][ne.hy])
				{
					visited[ne.px][ne.py][ne.hx][ne.hy] = true;
					if (ne.isMeet() || ne.isCollision(state))
					{
						cout << ne.cn << endl;
						return;
					}
					else
						que.push(ne);
				}
			}
		}
	}
	cout << "Impossible\n";//有可能不超过255，而且也没有找到。。。这里忘了。。。WA N次~~！！！
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (cin >> n >> m)
	{
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
			{
				cin >> a[i][j]; 
				if (a[i][j] == 'H'){		hx = i;		hy = j;		a[i][j] = '.';}
				if (a[i][j] == 'P'){		px = i;		py = j;		a[i][j] = '.';}
			}
		cin >> hmove;

		bfs();	
	}

	return 0;
}
