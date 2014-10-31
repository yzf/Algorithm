#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int n, ans;
char str[200];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	getchar();
	for (int cases = 1; cases <= n; cases ++)
	{
		map<char, int> cn;
		for (int i = 'a'; i <= 'z'; i ++)
			cn[i] = 0;

		gets(str);
		for (int i = 0; i < strlen(str); i ++)
			cn[ str[i] ] ++;

		gets(str);
		for (int i = 0; i < strlen(str); i ++)
			cn[ str[i] ] --;
		
		ans = 0;
		for (int i = 'a'; i <= 'z'; i ++)
			if (cn[i] > 0)
				ans += cn[i];
			else
				ans -= cn[i];

		printf( "Case #%d:  %d\n", cases, ans );
	}

    return 0;
}
