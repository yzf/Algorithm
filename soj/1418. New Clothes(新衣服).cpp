#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

const int MAX = 100;
int v, n, A, B, C, D, E;//分别表示上衣，裙子，裤子，靴子，连衣裙的数目
int	a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	while (n --)
	{
		set<int> ans;
		scanf( "%d%d%d%d%d", &A, &B, &C, &D, &E );
		for (int i = 0; i < A; i ++)
			scanf( "%d", &a[i] );
		for (int i = 0; i < B; i ++)
			scanf( "%d", &b[i] );
		for (int i = 0; i < C; i ++)
			scanf( "%d", &c[i] );
		for (int i = 0; i < D; i ++)
			scanf( "%d", &d[i] );
		for (int i = 0; i < E; i ++)
			scanf( "%d", &e[i] );

		for (int i = 0; i < A; i++)
			for (int j = 0; j < D; j ++)
			{
				for (int k = 0; k < B; k++)
					if (a[i]+d[j]+b[k] >= 0)
						ans.insert(a[i]+d[j]+b[k]);

				for (int l = 0; l < C; l ++)
					if (a[i]+d[j]+c[l] >= 0)
						ans.insert(a[i]+d[j]+c[l]);
			}

		for (int i = 0; i < E; i ++)
			for (int j = 0; j < D; j ++)
				if (e[i]+d[j] >= 0)
					ans.insert(e[i]+d[j]);
					
		printf( "%d\n", ans.size() );
	}

    return 0;
}
