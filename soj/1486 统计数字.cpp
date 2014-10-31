#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int n, nextNumber;
bool flag;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	flag = false;
    while (scanf( "%d", &n ) != EOF)
	{
		if (flag)
			printf( "\n" );

		map<int, int> numberSet;
		while (n --)
		{
			scanf( "%d", &nextNumber );
			numberSet[nextNumber] ++;
		}
		for (map<int, int>::iterator it = numberSet.begin();
			it != numberSet.end(); it ++)
		{
			printf( "%d %d\n", it->first, it->second );
		}
		flag = true;
	}

    return 0;
} 
