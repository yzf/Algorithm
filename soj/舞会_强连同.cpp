#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 210;
int n, tmp, ans;
vector<int> adj[MAX];
vector<int> reAdj[MAX];
vector<int> finish;
bool visited[MAX];

void dfsAdj(int id)
{
	visited[id] = true;
	for (int i = 0; i < adj[id].size(); i ++) 
	{
		int j = adj[id][i];
		if (!visited[j])
			dfsAdj(j);
	}
	finish.push_back(id);
}

void dfsReAdj(int id)
{
	visited[id] = false;
	for (int i = 0; i < reAdj[id].size(); i ++) 
	{
		int j = reAdj[id][i];
		if (visited[j])
			dfsReAdj(j);
	}
}

int main()  
{  
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	cin >> n;
	memset(visited, false, (n + 2) * sizeof(bool));
	for (int i = 1; i <= n; i ++) 
	{
		while (cin >> tmp && tmp) 
		{
			adj[i].push_back(tmp);
			reAdj[tmp].push_back(i);
		}
	}

	for (int i = 1; i <= n; i ++) 
		if (!visited[i]) 
			dfsAdj(i);

	ans = 0;
	for (int i = 0; i < finish.size(); i ++)
	{
		int j = finish[i];
		if (visited[j])
		{
			dfsReAdj(j);
			ans ++;
		}
	}

	cout << ans << endl;

    return 0;  
} 
