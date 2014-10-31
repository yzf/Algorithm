#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 2000001;
int c, n;
int t;
int ans;
bool flag[MAX];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &c, &n ) != EOF) {
		memset(flag, false, (n + 1) * sizeof(bool));
		int i, j;
		for (ans = 0, i = 0; i < c; i ++) {
			scanf( "%d", &t );
			for (j = 1; ; j ++) {
				int temp = j * t;
				if (temp > n) {
					break;
				}
				if (!flag[temp]) {
					flag[temp] = true;
					ans ++;
				}
			}
		}

		printf( "%d\n", ans );
	}

	return 0;
}
