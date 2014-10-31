#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a1, b1, a2, b2, c1, c2;
int aa[3], bb[3];
//删除的那个数要相同。。。WA N次。。。

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	int i, j;
	for (i = 100; i < 1000; i ++) {
		for (j = 100; j < 1000; j ++) {
			a1 = i;
			b1 = j;
			a2 = a1 / 10;
			b2 = b1 % 100;
			
			aa[0] = a1 % 10;
			aa[1] = (a1 / 10) % 10;
			aa[2] = a1 / 100;
			bb[0] = b1 % 10;
			bb[1] = (b1 / 10) % 10;
			bb[2] = b1 / 100;

			if (aa[0] == aa[1] && aa[1] == aa[2] &&
				aa[2] == bb[0] && bb[0] == bb[1] && bb[1] == bb[2]) {
				continue;
			}

			c1 = a1 * b2;
			c2 = a2 * b1;
			
			if (c1 == c2 && aa[0] == bb[2]) {
				printf( "%d / %d = %d / %d\n", a1, b1, a2, b2 );
			}
		}
	}

	return 0;
}
