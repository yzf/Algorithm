#include <iostream>
#include <queue>

using namespace std;

int dirx[] = {0, 1, 0, -1},
    diry[] = {-1, 0, 1, 0};
bool visited[100][100];
int m, n, ans;
char c;
struct Coordinate {
    int x, y;
    Coordinate() {}
    Coordinate(int tx, int ty) : x(tx), y(ty) {}
    bool isValid()
    {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return true;
    }
} cur, ne;
queue<Coordinate> que;

void bfs()
{
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i ++)
        {
            ne = Coordinate(cur.x+dirx[i], cur.y+diry[i]);
            if (ne.isValid() && !visited[ne.x][ne.y])
            {
                visited[ne.x][ne.y] = true;
                que.push(ne);
            }
        }
    }
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

    cin >> m >> n;
    for (int i = 0; i < m; i ++)
        for (int j = 0; j < n; j ++)
        {
            cin >> c;
            if (c == '0')
                visited[i][j] = true;
        }
        
    ans = 0;
    for (int i = 0; i < m; i ++)
        for (int j = 0; j < n; j ++)
        {
            if (!visited[i][j])
            {
                ans ++;
                que.push(Coordinate(i, j));
                bfs();
            }
        }
        
    cout << ans << endl;    
    
	return 0;
}
