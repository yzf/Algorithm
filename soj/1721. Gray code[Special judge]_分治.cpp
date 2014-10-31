#include <iostream>
#include <cstdio>

using namespace std;

int n;
char a[30];

inline void init()
{
    for (int i = 0; i < n; i ++)
        a[i] = '0';
    a[n] = '\0';
}

void solve(int k)
{
    if (k == n)
    {
        printf( "%s\n", a );
        return;
    }

    solve(k+1);
    a[k] = '1' + '0' - a[k];
    solve(k+1);
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

    while (scanf( "%d", &n ) && n != 0)
    {
		init();
		solve(0);
		printf( "\n" );
    }
    return 0;
}
