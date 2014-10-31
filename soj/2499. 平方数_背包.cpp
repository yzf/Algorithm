#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 60001;
int t, n;
vector<int> num;
int ans[MAX];
bool flag[MAX];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	memset(flag, false, sizeof(flag));
	memset(ans, 5, sizeof(ans));
	flag[0] = true;
	ans[0] = 0;

	int i, j, temp;
	for (i = 1; i * i < MAX; i ++) {
		num.push_back(i * i);
	}
	
	for (i = 0; i < num.size(); i ++) {
		temp = num[i];
		for (j = temp; j < MAX; j ++) {
			if (flag[j - temp]) {
				flag[j] = true;
				ans[j] = min(ans[j], ans[j - temp] + 1);
			}
		}
	}

	scanf( "%d", &t );
	while (t --) {
		scanf( "%d", &n );
		printf( "%d\n", ans[n] );
	}
	
	return 0;
}
