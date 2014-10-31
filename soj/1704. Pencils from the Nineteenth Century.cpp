#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, cases;
bool flag;
double sum;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	cases = 1;
	while (scanf( "%d", &n ) && n ) {

		flag = false;
		sum = (double)n;
		printf( "Case %d:\n", cases ++ );
		printf( "%d pencils for %d cents\n", n, n );
		for (int i = 1; i <= (int)(sum/4.0); i ++) {
			for (int j = 1; j <= (int)(sum/0.5); j ++) {
				int k = n - i - j;
				if (k <= 0) {
					break;
				}
				if (4.0*i+0.5*j+0.25*k == sum) {
					flag = true;
					printf( "%d at four cents each\n", i );
					printf( "%d at two for a penny\n", j );
					printf( "%d at four for a penny\n\n", k );
				}
			}
		}
		if (!flag) {
			printf( "No solution found.\n\n" );
		}
	}

    return 0;
}

