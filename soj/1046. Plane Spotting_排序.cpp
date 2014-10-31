#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

int runs, quarters, requested, mini, cn, a[300];

struct Period {
	int be, en;
	double per;
} period[200];

bool cmp(const Period &a, const Period &b)
{
	if (a.per > b.per)	return true;
	else if (a.per < b.per)	return false;
	else
	{
		if ((a.en-a.be) > (b.en-b.be))	return true;
		else if ((a.en-a.be) < (b.en-b.be))	return false;
		else	return a.en < b.en;
	}
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf( "%d", &runs );
	for (int cases = 1; cases <= runs; cases ++)
	{
		scanf( "%d%d%d", &quarters, &requested, &mini );
		for (int i = 0; i < quarters; i ++)
			scanf( "%d", &a[i] );

		cn = 0;
		for (int i = 0; i < quarters; i ++)
		{
			for (int j = i+mini-1; j < quarters; j ++)
			{
				double temp = (double)accumulate(a+i, a+j+1, 0);
				period[cn].be = i+1;
				period[cn].en = j+1;
				period[cn].per = temp / (j-i+1);
				cn ++;
			}
		}

		sort(period, period+cn, cmp);

		printf( "Result for run %d:\n", cases );
		for (int i = 0; i < cn && i < requested; i ++)
			printf( "%d-%d\n", period[i].be, period[i].en );
	}
    
    return 0;    
}
