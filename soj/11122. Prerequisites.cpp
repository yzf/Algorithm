#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int k, m, choice;
int c, r, courses;
int sum;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &k ) && k != 0)
	{
		set<int> choiceSet;
		sum = 0;
		scanf( "%d", &m );
		for (int i = 0; i < k; i ++)
		{
			scanf( "%d", &choice );
			choiceSet.insert(choice);
		}

		for (int j = 0; j < m; j ++)
		{
			scanf( "%d%d%", &c, &r );
			int cn = 0;
			for (int i = 0; i < c; i ++)
			{
				scanf( "%d", &courses );
				choiceSet.insert(courses);
				if (choiceSet.size() == k)
					cn ++;
				else
					choiceSet.erase(courses);
					
			}
			if (cn >= r)
				sum ++;
		}
		if (sum == m)
			printf( "yes\n" );
		else
			printf( "no\n" );
	}

    return 0 ;
}
