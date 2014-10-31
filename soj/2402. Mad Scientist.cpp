#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int k, p[30];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &k) && k) {
		int i, j;
		for (i = 1; i <= k; i ++) {
			scanf( "%d", &p[i] );
		}

		vector<int> ans;
		for (i = 1; i <= k; i ++) {
			for (j = 0; j < p[i] - p[i - 1]; j ++) {
				ans.push_back(i);
			}
		}
		for (i = 0; i < ans.size() - 1; i ++) {
			printf( "%d ", ans[i] );
		}
		printf( "%d\n", ans[ans.size()-1] );
	}
	
	return 0;
}
