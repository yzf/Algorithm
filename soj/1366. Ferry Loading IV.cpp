#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 10000;
int t, len, m, data;
int l[MAX], r[MAX], lcn, rcn;
int n1, n2;
char dir[10];

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &t );
	while (t --) {

		scanf( "%d%d", &len, &m );
		len *= 100;
		int i, j;
		for (lcn = rcn = i = 0; i < m; i ++) {
			scanf( "%d%s", &data, dir );
			if (dir[0] == 'l') {
				l[lcn ++] = data;
			}
			else {
				r[rcn ++] = data;
			}
		}

		for (n1 = i = 0; i < lcn; ) {
			int sum = l[i ++];
			while (sum + l[i] <= len) {
				sum += l[i ++];
			}
			n1 ++;
		}

		for (n2 = i = 0; i < rcn; ) {
			int sum = r[i ++];
			while (sum + r[i] <= len) {
				sum += r[i ++];
			}
			n2 ++;
		}
		
		if (n1 < n2) {
			printf( "%d\n", 2 * n2);
		}
		else {
			printf( "%d\n", 2 * n1 - 1 );
		}
	}
	
	return 0;
}
