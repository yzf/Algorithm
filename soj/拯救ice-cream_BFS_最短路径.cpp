#include <iostream>
#include <queue>

using namespace std;

int ans, t, col, row, v[30][30];
bool visited[30][30];
char c;

struct State {
    int x, y, cost;
    State() {}
    State(int tx, int ty, int tc) : x(tx), y(ty), cost(tc) {}
    bool isValid()
    {
        if (x < 0 || x >= row || y < 0 || y >= col)
            return false;
        return true;
    }
    bool operator < (const State &rhs) const 
    {
        return cost > rhs.cost;
    }
    bool operator == (const State &rhs) const 
    {
        return x == rhs.x && y == rhs.y;
    }
} cur, ne, target;

priority_queue<State> que;

int abs(int a)
{
    if (a < 0)        return -a;
    else return a;
}

int minCost()
{
    while (!que.empty())
    {
        cur = que.top();  que.pop();
        
        for (int i = -1; i <= 1; i ++)
		{
			for (int j = -1; j <= 1; j ++)
			{
				if (abs(i+j) != 1)
					continue;
					
				ne.x = cur.x + i;
				ne.y = cur.y + j;
				ne.cost = cur.cost + v[ne.x][ne.y];

				if (ne.isValid() && !visited[cur.x+i][cur.y+j])
				{
					que.push(ne);
					visited[ne.x][ne.y] = true;
					if (ne == target)
						return ne.cost;
				}
			}
		}
    }
    return -1;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

    cin >> t >> col >> row;
    for (int i = 0; i < row; i ++)
        for (int j = 0; j < col; j ++)
        {
            cin >> c;
            if (c == 's')
            {
                que.push(State(i, j, 0));
                visited[i][j] = true;
            }
            else if (c == '.')
                v[i][j] = 1;
            else if (c == 'o')
                visited[i][j] = true;
            else if (c == '#')
                v[i][j] = 2;
            else 
            {
                target = State(i, j, 0);
                v[i][j] = 1;
            }
        }
    
    ans = minCost();
    if (ans < t)   cout << ans << endl;
    else cout << 55555 << endl;
    
	return 0;
}
