#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool flag;
int cases, ans, target, a[5]; 

inline bool update(int a[], int index)
{
	if (a[index] == target)
	{
		ans = target;
		return true;
	}
	else if (a[index] > ans && a[index] < target)
		ans = a[index];

	return false;
}

bool dfs(int n)
{
    for (int i = 0; i < n; i ++)
	{
		for (int j = i+1; j < n; j ++)
		{
			int temp1, temp2;
			temp1 = a[i];	temp2 = a[j];
			a[j] = a[n-1];
			// + 
			a[i] = temp1 + temp2;
			if (update(a, i))
				return true;
			if (dfs(n - 1))
				return true;
			// -
			a[i] = temp1 - temp2;
			if (update(a, i))
				return true;
			if (dfs(n - 1))
				return true;

			a[i] = temp2 - temp1;
			if (update(a, i))
				return true;
			if (dfs(n - 1))
				return true;
			// * 
			a[i] = temp1 * temp2;
			if (update(a, i))
				return true;
			if (dfs(n - 1))
				return true;
			// /
			if (temp2 != 0 && temp1%temp2 == 0)
			{
				a[i] = temp1 / temp2;
				if (update(a, i))
					return true;
				if (dfs(n - 1))
					return true;
			}

			if (temp1 != 0 && temp2%temp1 == 0)
			{
				a[i] = temp2 / temp1;
				if (update(a, i))
					return true;
				if (dfs(n - 1))
					return true;
			}
			
			a[i] = temp1;
			a[j] = temp2;
		}
	}

    return false;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

    scanf( "%d", &cases );
	while (cases --)
	{
		flag = false;
		ans = -10000000;

		for (int i = 0; i < 5; i ++)
			scanf( "%d", &a[i] );
		scanf( "%d", &target );

		for (int i = 0; i < 5; i ++)
			if (a[i] == target)
			{
				flag = true;
				ans = target;
				break;
			}
		
		if (!flag)
			dfs(5);

		printf( "%d\n", ans );
	}

    return 0;
}
