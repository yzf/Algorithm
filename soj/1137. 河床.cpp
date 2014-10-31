#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int n, k, maxLength, maxDepth, minDepth, l, r;
int depth[30001];
set<int> depthSet;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> n >> k;
	for (int i = 0; i < n; i ++)
		scanf( "%d", &depth[i] );

	maxLength = 1;
	maxDepth = minDepth = depth[0];
	l = r = 0;
	depthSet.insert(depth[r]);
	while (r < n)
	{        
		if (maxDepth - minDepth > k)
		{
			depthSet.erase(depth[l]);
			l ++;
		}
		else
		{
			if (r-l+1 > maxLength)
				maxLength = r-l+1;
			r ++;
			depthSet.insert(depth[r]);
		}
			
		minDepth = *depthSet.begin();
		maxDepth = *(-- depthSet.end());
	}
	printf( "%d\n", maxLength );

	return 0;
}
