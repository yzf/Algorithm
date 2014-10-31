#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, lenA, lenB;
bool dp[210][210];
char a[210], b[210], c[410];

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    scanf( "%d", &n );
    for (int t = 1; t <= n; t ++)
    {
		memset(dp, false, sizeof(dp));
		scanf( "%s%s%s", a, b, c );

		lenA = strlen(a);
		lenB = strlen(b);
		dp[0][0] = true;
		for (int i = 0; i <= lenA; i ++)
		{
			for (int j = 0; j <= lenB; j ++)
			{
				if (i+j == 0)   
                {   
                    continue;   
                }   
                if (i == 0)   
                {   
                   dp[0][j] = dp[0][j-1] && c[j-1]==b[j-1];   
                }   
                else if (j == 0)   
                {   
                   dp[i][0] = dp[i-1][0] && c[i-1]==a[i-1];   
                }   
                else  
                {   
                  dp[i][j] = dp[i-1][j] && c[i+j-1]==a[i-1]   
                             || dp[i][j-1] && c[i+j-1]==b[j-1];   
                } 
			}
		}

		printf( "Data set %d: %s\n", t, dp[lenA][lenB] ? "yes": "no" );   
    }
    
    return 0;
}
