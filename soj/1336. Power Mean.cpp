#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

char str[500];
char *data;
double p;
double ans;
double x[100];
int cn;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf ( "%lf", &p ) != EOF) {
		getchar();
		gets(str);

		data = strtok(str, " ");
		cn = 0;
		while (data) {
			sscanf( data, "%lf", &x[cn ++] );
			data = strtok(NULL, " ");
		}

		ans = 0.0;
		for (int i = 0; i < cn; i ++) {
			ans += (pow(x[i], p));
		}
		ans /= (double)cn;
		ans = pow(ans, 1.0/p);

		printf( "%.3lf\n", ans );
	}

    return 0;
}
