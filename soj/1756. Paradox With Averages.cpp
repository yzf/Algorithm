#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 200010;
int t, ns, ne, ans;
int s[MAX], e[MAX];
double sum, av1, av2;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &t );
	while (t --) {
		scanf( "%d%d", &ns, &ne );
		int i;
		sum = 0.0;
		for (i = 0; i < ns; i ++) {
			scanf( "%d", &s[i] );
			sum += s[i];
		}
		av1 = sum / ns;

		sum = 0.0;
		for (i = 0; i < ne; i ++) {
			scanf( "%d", &e[i] );
			sum += e[i];
		}
		av2 = sum / ne;

		ans = 0;
		for (i = 0; i < ns; i ++) {
			double temp = (double)s[i];
			if (temp < av1 && temp > av2) {
				ans ++;
			}
		}
		printf( "%d\n", ans );
	}

	return 0;
}