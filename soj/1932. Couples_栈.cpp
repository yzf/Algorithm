#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100001;
int t, n, i;
int len;
int a, b;
int flag[2 * MAX], stk[2 * MAX];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --) {

		scanf( "%d", &n );
		for (i = 0; i < n; i ++) {
			scanf( "%d%d", &a, &b );
			flag[a] = flag[b] = i;
		}

		a = 1;	b = 2 * n;
		while (a < b && flag[a] == flag[b]) {
			a ++;
			b --;
		}

		len = 0;
		for (i = a; i <= b; i ++) {
			if (len == 0 || flag[i] != flag[ stk[len - 1] ]) {
				stk[len ++] = i;
			}
			else if (len != 0 && flag[i] == flag[ stk[len - 1] ]) {
				len --;
			}
		}
		if (len == 0) {
			printf( "Yes\n" );
		}
		else {
			printf( "No\n" );
		}
	}
	
	return 0;
}
