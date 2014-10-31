#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 40001;
int cases, n, data, len, stk[MAX];
//stk[i]表示长度为i的不降子序列的第i个数的最小值
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &cases );
	while (cases --) {
		scanf( "%d", &n );
		len = 0;
		while (n --) {
			scanf( "%d", &data );
			if (len == 0 || data > stk[len]) {
				stk[++ len] = data;
			}
			else {
				int l = 1;
				int r = len;
				int mid = (l + r) / 2;
				while (l < r) {
					if (data < stk[mid]) {
						r = mid;
					}
					else {
						l = mid + 1;
					}
					mid = (l + r) / 2;
				}
				stk[mid] = data;
			}
		}
		printf( "%d\n", len );
	}

    return 0;
}
