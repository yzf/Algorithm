#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 40;
int n, ans[MAX], sum[MAX];;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	memset(ans, 0, sizeof(ans));
	memset(sum, 0, sizeof(sum));
	
	ans[0] = 1;		ans[2] = 3;
	sum[0] = 1;		sum[2] = 4;
	for (int i = 4; i <= 30; i += 2)
	{
		ans[i] = ans[2]*ans[i-2] + 2*sum[i-4];
		sum[i] = sum[i-2] + ans[i];
	}

	while (scanf( "%d", &n ) && n != -1)
		printf( "%d\n", ans[n] );
  
    return 0;
}
