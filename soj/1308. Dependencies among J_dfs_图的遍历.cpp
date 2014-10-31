#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int MAX = 10010;
int n, m, ans, cost[MAX];
bool visited[MAX];
string line;
vector<int> data, father[MAX];

void getData()
{
	int num = 0;
	for (int i = 0; i < line.length(); i ++) {
		if (line[i] == ' ') {
			data.push_back(num);
			num = 0;
		}
		else {
			num = 10 * num + (line[i] - '0');
			if (i == line.length()-1) {
				data.push_back(num);
			}
		}
	}
}

void dfs(int id)
{
	ans += cost[id];
	visited[id] = true;
	for (int i = 0; i < father[id].size(); i ++) {
		int fa = father[id][i];
		if (!visited[fa]) {
			dfs(fa);
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (getline(cin, line)) {

		data.clear();
		getData();
		n = data[0];
		if (n == 0)	break;
		m = data[1];

		for (int i = 1; i <= n; i ++) {
			visited[i] = false;
			father[i].clear();

			getline(cin, line);
			data.clear();
			getData();
			cost[i] = data[0];

			for (int j = 1; j < data.size(); j ++) {
				father[i].push_back(data[j]);
			}
		}

		ans = 0;
		dfs(m);
		printf( "%d\n", ans );
	}

    return 0;
}
