#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 500;

bool flag = false;
int a, b, c, d;
int aa[MAX], bb[MAX], cc[MAX], dd[MAX];
struct ss {
	int ccc;
	int ddd;
	int sum;
} ssum[MAX*MAX];

bool cmp(const ss &x, const ss &y)
{
	return (x.sum < y.sum);
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	scanf( "%d%d%d%d", &a, &b, &c, &d );
	for (int i = 0; i < a; i ++)
		scanf( "%d", &aa[i] );
	for (int i = 0; i < b; i ++)
		scanf( "%d", &bb[i] );
	for (int i = 0; i < c; i ++)
		scanf( "%d", &cc[i] );
	for (int i = 0; i < d; i ++)
		scanf( "%d", &dd[i] );
	
	int n = 0;
	for (int i = 0; i < c; i ++)
		for (int j = 0; j < d; j ++)
		{
			ssum[n].ccc = cc[i];
			ssum[n].ddd = dd[j];
			ssum[n ++].sum = cc[i] + dd[j];
		}

	for (int i = 0; i < a; i ++)
	{
		for (int j = 0; j < b; j ++)
		{
			int temp = aa[i] + bb[j];
			for (int k = 0; k < n; k ++)
			{
				if (ssum[k].sum + temp == 0)
				{
					printf( "%d %d %d %d\n", aa[i], bb[j], ssum[k].ccc, ssum[k].ddd );
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			break;
	}

    return 0;
}
