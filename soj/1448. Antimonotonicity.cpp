#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 30010;
int t, n, cur, pre;
int ans;
bool flag;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --) {
		scanf( "%d", &n );
		scanf( "%d", &pre );
		ans = 1;	flag = false;
		for (int i = 1; i < n; i ++) {
			scanf( "%d", &cur );
			if (!flag && cur < pre) {
				ans ++;
				flag = true;
			}
			if (flag && cur > pre) {
				ans ++;
				flag = false;
			}
			pre = cur;
		}
		
		printf( "%d\n", ans );
	}

	return 0;
}
