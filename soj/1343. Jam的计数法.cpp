#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int s, t, w, start, en, cn;
char jim[30], temp[30];

void dfs(int len, int start)
{
	if (cn == 5)
		return ;
	if (len == w)
	{
		temp[len] = '\0';
		if (strcmp(temp, jim) > 0)
		{
			printf( "%s\n", temp );
			cn ++;
			return ;
		}
	}
	for (int i = start; i <= en; i ++)
	{
		temp[len] = i;
		dfs(len+1, i+1);
	}
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d%d%d", &s, &t, &w ) != EOF)
	{
		cn = 0;
		scanf( "%s", jim );
		start = 'a' + s - 1;
		en = 'a' + t - 1;
		dfs(0, start);
	}

    return 0;
}
