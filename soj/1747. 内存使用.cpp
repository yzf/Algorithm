#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100001;
bool flag;
int cases, k, n;
struct pp{
	int r;
	int s;
} progress[MAX];

bool cmp(const pp &a, const pp &b)
{
	return (a.r > b.r);
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	scanf( "%d", &cases );
	while (cases --)
	{
		flag = true;
		scanf( "%d%d", &k, &n );
		for (int i = 0; i < n; i ++)
			scanf( "%d%d", &progress[i].r, &progress[i].s );

		sort(progress, progress+n, cmp);
		for (int i = 0; i < n; i ++)
		{
			if (k < progress[i].r || k < progress[i].s)
			{
				flag = false;
				printf( "No\n" );
				break;
			}
			k -= progress[i].s;
		}
		if (flag)
			printf( "Yes\n" );
	}
    
    return 0;
}
