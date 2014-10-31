#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
	int fr, to, id, len;
} road;

struct Cross {
	int distance;//到 1 的距离 
	vector<Road > roads;
} cross[201];

bool visitedCross[201], visitedRoad[10001];
int cases, n, m, fr, to, dist;
vector<Road > minHeap;//用堆来优化最短路径算法 

bool cmp(const Road &lhs, const Road &rhs)
{
	return lhs.len > rhs.len;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	while (cases --)
	{
		memset(visitedCross, false, sizeof(visitedCross));
		memset(visitedRoad, false, sizeof(visitedRoad));

		scanf( "%d%d", &n, &m );

		cross[1].roads.clear();
		cross[1].distance = 0;
		for (int i = 2; i <= n; i ++)
		{
			cross[i].roads.clear();
			cross[i].distance = -1;
		}
		while (m --)
		{
			scanf( "%d%d%d", &fr, &to, &dist );
			road.id = m;	road.len = dist;
			road.fr = fr;	road.to = to;	cross[ fr ].roads.push_back(road);
			road.fr = to;	road.to = fr;	cross[ to ].roads.push_back(road);
		}

		for (int i = 0; i < cross[1].roads.size(); i ++)
		{
			minHeap.push_back(cross[1].roads[i]);
			push_heap(minHeap.begin(), minHeap.end(), cmp);
		}
		visitedCross[1] = true;
		while (!minHeap.empty())
		{
			while (!minHeap.empty()) 
			{
				if (visitedRoad[ minHeap[0].id ] || visitedCross[ minHeap[0].to ])
				{
					pop_heap(minHeap.begin(), minHeap.end(), cmp);
					minHeap.pop_back();
				}
				else	break;
			}
			if (minHeap.empty())	break;

			road = minHeap[0];
			pop_heap(minHeap.begin(), minHeap.end(), cmp);		minHeap.pop_back();
			visitedRoad[ road.id ] = true;		visitedCross[ road.to ] = true;
			cross[ road.to ].distance = road.len;

			for (int i = 0; i < cross[ road.to ].roads.size(); i ++)
			{
				cross[ road.to ].roads[i].len += cross[ road.to ].distance;
				minHeap.push_back(cross[ road.to ].roads[i]);
				push_heap(minHeap.begin(), minHeap.end(), cmp);
			}
		}
		printf( "%d\n", cross[n].distance );
	}

	return 0;
}
