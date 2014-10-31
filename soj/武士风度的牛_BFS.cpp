#include <iostream>
#include <queue>

using namespace std;

int dirx[8] = {1, 2, 2, 1, -1, -2, -2, -1},
    diry[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool visited[151][151];
int xx, yy, bex, bey, enx, eny;
char c;
struct State {
    int x, y, cn;
    State(){}
    State(int tx, int ty, int tcn) : x(tx), y(ty), cn(tcn) {}
    bool isValid()
    {
        if (x < 0 || x >= xx || y < 0 || y >= yy)
            return false;
        return true;
    }
} cur, ne;
queue<State> que;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

    cin >> yy >> xx;
    for (int i = 0; i < xx; i ++)
        for (int j = 0; j < yy; j ++)
        {
            cin >> c;
            if (c == '*')
                visited[i][j] = true;
            else if (c == 'K')
            {
                bex = i;  bey = j;
            }
            else if (c == 'H')
            {
                enx = i;  eny = j;
            }
        }

    que.push(State(bex, bey, 0));
    visited[bex][bey] = true;
    while (!que.empty())
    {
        cur = que.front();   que.pop();
        if (cur.x == enx && cur.y == eny)
        {
            cout << cur.cn << endl;
            break;
        }
        for (int i = 0; i < 8; i ++)
        {
            ne = State(cur.x+dirx[i], cur.y+diry[i], cur.cn+1);
            if (ne.isValid() && !visited[ne.x][ne.y])
            {
                que.push(ne);
                visited[ne.x][ne.y] = true;
            }
        }
    }

	return 0;
}
