#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define INT64 long long
int t;
int ans;
INT64 l;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --) {
		scanf( "%lld", &l );
		INT64 i, j, k;
		for (ans = 0, i = 1; i < l / 3; i ++) {
			INT64  temp1 = l * l - 2 * i * l;
			INT64  temp2 = 2 * l - 2 * i;

			j = temp1 / temp2;
			if (j * temp2 != temp1) {
				continue;
			}
			if (j < i) {
				continue;
			}

			k = l - i - j;
			if (k <= j) {
				continue;
			}
			ans ++;
		}
		printf( "%d\n", ans );
	}

	return 0;
}
