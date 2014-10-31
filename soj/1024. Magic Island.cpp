#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 10001;

struct Road {
	int cityTo;
	int dist;
	int roadNumber;
} ;

struct City {
	vector<Road> roads;
	int distToCap;
	City() : distToCap(0) {};
} ;

bool visited[MAX];
int n, k;
int x, y, d;
int longest;
Road newRoad1, newRoad2;

void dfs(int no, City city[])
{
	for (int i = 0; i < city[no].roads.size(); i ++)
	{ 
		int nextRoad = city[no].roads[i].roadNumber;
		if (!visited[ nextRoad ])
		{
			int temp = city[ city[no].roads[i].cityTo ].distToCap;
			city[ city[no].roads[i].cityTo ].distToCap = city[no].distToCap + city[no].roads[i].dist;
			//更新最长路线长度
			if (city[ city[no].roads[i].cityTo ].distToCap > longest)
				longest = city[ city[no].roads[i].cityTo ].distToCap;

			visited[ nextRoad ] = true;
			dfs(city[no].roads[i].cityTo, city);
			//还原状态
			visited[ nextRoad ] = false;
			city[ city[no].roads[i].cityTo ].distToCap = temp;
		}
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d%d", &n, &k ) != EOF)
	{
		memset(visited, false, sizeof(visited));
		longest = 0;

		City city[MAX]; 
		for (int i = 1; i < n; i ++)
		{
			scanf( "%d%d%d", &x, &y, &d );
			newRoad1.cityTo = y;
			newRoad2.cityTo = x;
			newRoad1.dist = newRoad2.dist = d;
			newRoad1.roadNumber = newRoad2.roadNumber = i;
			city[x].roads.push_back(newRoad1);
			city[y].roads.push_back(newRoad2);
		}

		dfs(k, city);

		printf( "%d\n", longest );
	}

	return 0;
}
