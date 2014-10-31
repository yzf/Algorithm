#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	int weight[4];
	int rate[4];
	int customWeight, bestPrice, add, test = 1;

	weight[3] = 1000;
	while (scanf( "%d%d", &weight[0], &rate[0] )!=EOF)
	{  
        printf( "Set number %d:\n", test ++ );
        
		for (int i = 1; i < 3; i ++)
			scanf( "%d%d", &weight[i], &rate[i] );
		scanf( "%d", &rate[3] );

		for (scanf( "%d", &customWeight ); 
			customWeight != 0; 
			scanf( "%d", &customWeight ))
		{
            
			add = 0;
			if (customWeight <= weight[0])
			{
				bestPrice = customWeight * rate[0];
				if ((weight[0]+1) * rate[1] < bestPrice)
				{
					bestPrice = (weight[0]+1) * rate[1];
				    add = weight[0] + 1 - customWeight; 
				}
			}
			else if (customWeight <= weight[1])
			{
				bestPrice = customWeight * rate[1];
				if ((weight[1]+1) * rate[2] < bestPrice)
				{
					bestPrice = (weight[1]+1) * rate[2];
					add = weight[1] + 1 - customWeight;
				}
			}
			else if (customWeight <= weight[2])
			{
				bestPrice = customWeight * rate[2];
				if ((weight[2]+1) * rate[3] < bestPrice)
				{
					bestPrice = (weight[2]+1) * rate[3];
					add = weight[2] + 1 - customWeight;
				}
			}
			else
			{
				bestPrice = customWeight * rate[3];
			}
			printf( "Weight (%d) has best price $%d (add %d pounds)\n", customWeight, bestPrice, add );
		}
		printf( "\n" );
	}
    
    return 0;
}
