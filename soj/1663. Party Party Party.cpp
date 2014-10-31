#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int parties, ans, timeList[25];
struct party {
	int start;
	int end;
} partyList[100];

bool cmp1(const party &a, const party &b)
{
	return a.start < b.start;
}
bool cmp2(const party &a, const party &b)
{
	return a.end < b.end;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	int day = 1;
	while (scanf( "%d", &parties ) && parties != 0)
	{
		ans = 0;
		memset(timeList, 0, sizeof(timeList));
		for (int i = 0; i < parties; i ++)
			scanf( "%d%d", &partyList[i].start, &partyList[i].end );

		sort(partyList, partyList+parties, cmp1);
		stable_sort(partyList, partyList+parties, cmp2);

		for (int i = 0; i < parties; i ++)
		{
			for (int j = partyList[i].start; j < partyList[i].end; j ++)
			{
				if (timeList[j] < 2)
				{
					timeList[j] ++;
					ans ++;
					break;
				}
			}
		}

		printf( "On day %d Emma can attend as many as %d parties.\n", day ++, ans );
	}
    
	return 0;
}
