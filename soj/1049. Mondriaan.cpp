#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000001;
int cases, n, ans[MAX];

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
	ans[0] = 1;		ans[1] = 2;		ans[2] = 7;
	for (int i = 3; i < MAX; i ++)
		ans[i] = (3*ans[i-1] + ans[i-2] - ans[i-3] + 10) % 10;

    scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d", &n );
		printf( "%d\n", ans[n] );
	}

    return 0;
}
