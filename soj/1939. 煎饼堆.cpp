#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cases, n, a[31];

void flip(int k)
{
	for (int i = 0, j = n-k; i < j; i ++, j--)
		swap(a[i], a[j]);
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> cases;
	while (cases --)
	{
		cin >> n;
		bool flag = true;
		cin >> a[0];
		for (int i = 1; i < n; i ++)
		{
			cin >> a[i];
			if (a[i] < a[i-1])	flag = false;
		}

		if (flag)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n-1; i ++)
		{
			int k = 0;
			for (int j = 1; j < n-i; j ++)
				if (a[j] > a[k])
					k = j;
			
			if (k == n-i-1)
				continue;
			if (k != 0)
			{
				flip(n-k);
				cout << n-k << " ";
			}
			flip(i+1);
			cout << i+1 << " ";
		}
		cout << 0 << endl;
	}	

	return 0;
}
