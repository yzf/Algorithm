#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Contestant {
	char name[15];
	int solved;
} ;

bool cmp1(const Contestant &a, const Contestant &b)
{
	return (a.solved < b.solved);
}

bool cmp2(const Contestant &a, const Contestant &b)
{
	return (a.solved > b.solved);
}

const int MAX = 100001;

int t, cn;
char key[10];
Contestant temp;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf( "%d", &t );
	for (int i = 1; i <= t; i ++)
	{
		if (i != 1)
			printf( "\n" );
		cn = 0;
		vector<Contestant > smallestHeap, biggestHeap;

		while (true)
		{
			scanf( "%s", key );
			if (key[0] == 'A')
			{
				scanf( "%s%d", temp.name, &temp.solved );
				cn ++;
				if (cn%2 == 1)
				{
					biggestHeap.push_back(temp);
					push_heap(biggestHeap.begin(), biggestHeap.end(), cmp1);
				}
				else
				{
					smallestHeap.push_back(temp);
					push_heap(smallestHeap.begin(), smallestHeap.end(), cmp2);
				}
				if (!biggestHeap.empty() && !smallestHeap.empty() && cmp2(biggestHeap[0], smallestHeap[0]))
				{//Î¬»¤
					temp = biggestHeap[0];
					pop_heap(biggestHeap.begin(), biggestHeap.end(), cmp1);
					biggestHeap.pop_back();
					biggestHeap.push_back(smallestHeap[0]);
					push_heap(biggestHeap.begin(), biggestHeap.end(), cmp1);

					pop_heap(smallestHeap.begin(), smallestHeap.end(), cmp2);
					smallestHeap.pop_back();
					smallestHeap.push_back(temp);
					push_heap(smallestHeap.begin(), smallestHeap.end(), cmp2);
				}
			}
			else if (key[0] == 'Q')
			{
				if (cn%2 == 1)
					printf( "%s\n", biggestHeap[0].name );
				else
					printf( "No one!\n" );
			}
			else
			{
				if (cn%2 == 1)
					printf( "%s is so poor.\n", biggestHeap[0].name );
				else
					printf( "Happy BG meeting!!\n" );
				break;
			}
		}
	}

	return 0;
}
