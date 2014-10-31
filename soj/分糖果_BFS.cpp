#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[100001];
int cn[100001];
int n, p, c, m, a, b, cur;
vector<int> ad[100001];
queue<int> que;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> n >> p >> c >> m;
	while (p --)
    {
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    cn[c] = 1;
    que.push(c);
    visited[c] = true;
    while (!que.empty())
    {
        cur = que.front();  que.pop();
        for (int i = 0; i < ad[cur].size(); i ++)
        {
            if (!visited[ ad[cur][i] ])
            {
                visited[ ad[cur][i] ] = true;
                que.push(ad[cur][i]);
                cn[ ad[cur][i] ] = cn[cur] + 1;
            }
        }
    }
    cout << cn[cur] + m << endl;

	return 0;
}
