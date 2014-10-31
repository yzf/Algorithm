#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

int n, p, a;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF)
	{
		map<int, multiset<int> > planet;
		map<int, multiset<int> >::iterator it;
		while (n --)
		{
			scanf( "%d%d", &p, &a );
			planet[p].insert(a);
		}
		for (it = planet.begin(); it != planet.end(); it ++)
		{
			multiset<int> temp = it->second;
			multiset<int>::iterator itt = temp.begin();
			if (temp.size() % 2 == 1)
			{
				for (int i = 0; i < temp.size()/2; i ++)
					itt ++;
				printf( "%d %d\n", it->first, *itt );
			}
			else
			{
				for (int i = 1; i < temp.size()/2; i ++)
					itt ++;
				printf( "%d %d\n", it->first, ((*itt ++)+(*itt))/2 );
			}
		}
	}

    return 0;
}
