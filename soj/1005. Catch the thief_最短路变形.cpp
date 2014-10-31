#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int oo = 1 << 30;
int n;
int a[MAX][MAX];
int dij1[MAX], dij2[MAX];
bool visited[MAX];

void dijkstra1()
{
	memset(visited, false, sizeof(visited));
	visited[0] = true;
	for (int time = 1; time < n; time ++)
	{
		int min = oo;
		int id = -1;
		for (int i = 0; i < n; i ++)
			if (!visited[i] && dij1[i] < min)
			{
				min = dij1[i];
				id = i;
			}
		visited[id] = true;
		for (int i = 0; i < n; i ++)
			if (a[id][i] != oo && (dij1[id] + a[id][i] < dij1[i]))
				dij1[i] = dij1[id] + a[id][i];
	}
}

void dijkstra2()
{
	memset(visited, false, sizeof(visited));
	visited[n - 1] = true;
	for (int time = 1; time < n; time ++)
	{
		int min = oo;
		int id = -1;
		for (int i = 0; i < n; i ++)
			if (!visited[i] && dij2[i] < min)
			{
				min = dij2[i];
				id = i;
			}
		visited[id] = true;
		for (int i = 0; i < n; i ++)
			if (a[id][i] != oo && (dij2[id] + a[id][i] < dij2[i]))
				dij2[i] = dij2[id] + a[id][i];
	}
}


int main()  
{  
    //freopen( "input.txt", "r", stdin );
   // freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) && n)
	{
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
			{
				scanf( "%d", &a[i][j] );
				if (a[i][j] == -1)
					a[i][j] = oo;
			}

		for (int i = 0; i < n; i ++)
			dij1[i] = a[0][i];
		for (int i = 0; i < n; i ++)
			dij2[i] = a[n - 1][i];
		dijkstra1();
		dijkstra2();

		int ans = 2;
		for (int i = 1; i < n - 1; i ++)
			if (dij1[i] + dij2[i] == dij1[n - 1])
				ans ++;
		printf( "%d\n", ans );
	}
	
    return 0;  
} 
