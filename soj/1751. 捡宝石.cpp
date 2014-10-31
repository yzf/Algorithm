#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int s, n, total;

enum Mark {
	ROW, DOWN, COL, UP
};

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d", &n, &s )) {
		if (n == -1 && s == -1)	break;

		int ans = 0, i = 1, j = 1;	
		double sum = 0.0;
		total = (s+1) * s / 2;
		Mark sign = ROW;

		while (true) {
			sum += (double)i / (double)j;
			if (sum >= (double)n)	
				break;
			ans ++;
			if (ans >= total)	
				break;

			if (sign == ROW && i == 1) {
				j ++;
				sign = DOWN;
				continue;
			} 
			if (sign == COL && j == 1) {
				i ++;
				sign = UP;
				continue;
			}
			if (sign == DOWN) {
				i ++;
				j --;
				if (j == 1)
					sign = COL;
				if (j == 1 && i == s)
					sign = UP;
				continue;
			}
			if (sign == UP) {
				i --;
				j ++;
				if (i == 1)
					sign = ROW;
				if (i == 1 && j == s)
					sign = DOWN;
			    continue;
			}
		}
		printf( "%d\n", ans );
	}

    return 0;
}
