#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n, m;
double ne, score[100], mini[100], maxu[100];

int main()
{  
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
   
	scanf( "%d", &cases );
	while (cases --)
	{
		scanf( "%d%d", &n, &m );
		memset(score, 0, sizeof(score));
		for (int j = 0; j < m; j ++)
		{
			scanf( "%lf", &ne );
			mini[j] = maxu[j] = ne;
		}
		for (int j = 0; j < m; j ++)
		{
			scanf( "%lf", &ne );
			mini[j] = min(ne, mini[j]);
			maxu[j] = max(ne, maxu[j]);
		}
		for (int i = 0; i < n-2; i ++)
			for (int j = 0; j < m; j ++)
			{
				scanf( "%lf", &ne );
				if (ne < mini[j])	
				{
					score[j] += mini[j];
					mini[j] = ne;
				}
				else if (ne > maxu[j])
				{
					score[j] += maxu[j];
					maxu[j] = ne;
				}
				else
					score[j] += ne;
			}

		for (int i = 0; i < m; i ++)
			printf( "%.2lf\n", score[i]/(double)(n-2) );

	}

    return 0;  
}  
