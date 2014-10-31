#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int cases, row, column, a1, b1, a2, b2, ans;
int a[102][102], visited[102][102];

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
	Point temp, temp2;
	while (!minHeap.empty())
	{
		temp = minHeap.front();
		pop_heap(minHeap.begin(), minHeap.end());
		minHeap.pop_back();

		for (int i = -1; i <= 1; i ++)
		{
			for (int j = -1; j <= 1; j ++)
			{
				if (abs(i+j) != 1)
					continue;

				if (!visited[temp.x+i][temp.y+j])
				{
					temp2.x = temp.x + i;
					temp2.y = temp.y + j;
					temp2.cost = temp.cost + a[temp.x+i][temp.y+j];
					minHeap.push_back(temp2);
					push_heap(minHeap.begin(), minHeap.end());
					visited[temp2.x][temp2.y] = true;
					if (temp2.x == a2 && temp2.y == b2)
						return temp2.cost;
				}
			}
		}
	}
	return -1;
}

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d%d", &row, &column );
		for (int i = 1; i <= row; i ++)
			for (int j = 1; j <= column; j ++)
			{
				scanf( "%d", &a[i][j] );
				visited[i][j] = false;
			}

		scanf( "%d%d%d%d", &a1, &b1, &a2, &b2 );

		for (int i = 1; i <= row; i ++)
			visited[i][0] = visited[i][column+1] = true;

		for (int i = 1; i <= column; i ++)
			visited[0][i] = visited[row+1][i] = true;

		vector< Point > minHeap;
		Point temp;
		temp.x = a1;	temp.y = b1;	temp.cost = a[a1][b1];
		visited[a1][b1] = true;
		if (a1 == a2 && b1 == b2)
			ans = temp.cost;
		else
		{
			minHeap.push_back(temp);
			push_heap(minHeap.begin(), minHeap.end());
			ans = minCost(minHeap);
		}

		printf( "%d\n", ans );
	}

    return 0;
}

