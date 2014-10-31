#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, ans;
int a[127][127], visited[127][127];

struct Point {
	int x, y, cost;
	bool operator < (const Point &rhs) const 
	{
		return cost > rhs.cost;
	}
} ;
//×î¶ÌÂ·¾¶ 
int minCost(vector< Point > &minHeap)
{
	Point temp1, temp2;
	while (!minHeap.empty())
	{
		temp1 = minHeap.front();
		pop_heap(minHeap.begin(), minHeap.end());
		minHeap.pop_back();

		for (int i = -1; i <= 1; i ++)
		{
			for (int j = -1; j <= 1; j ++)
			{
				if (abs(i+j) != 1)
					continue;

				if (!visited[temp1.x+i][temp1.y+j])
				{
					temp2.x = temp1.x + i;
					temp2.y = temp1.y + j;
					temp2.cost = temp1.cost + a[temp2.x][temp2.y];
					minHeap.push_back(temp2);
					push_heap(minHeap.begin(), minHeap.end());
					visited[temp2.x][temp2.y] = true;
					if (temp2.x == n && temp2.y == n)
						return temp2.cost;
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

	int cases = 1;
	while (scanf( "%d", &n ) && n != 0)
	{
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
			{
				scanf( "%d", &a[i][j] );
				visited[i][j] = false;
			}

		for (int i = 1; i <= n; i ++)
			visited[i][0] = visited[i][n+1] = visited[0][i] = visited[n+1][i] = true;

		vector< Point > minHeap;
		Point temp;
		temp.x = 1;	temp.y = 1; temp.cost = a[1][1];
		minHeap.push_back(temp);
		push_heap(minHeap.begin(), minHeap.end());
		visited[temp.x][temp.y] = true;

		ans = minCost(minHeap);

		printf( "Problem %d: %d\n", cases ++, ans );
	}

    return 0;
}

