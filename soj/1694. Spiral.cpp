#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cases, n, m, r, c;
//很烦的一题。。。 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> cases;
	while (cases --)
	{
		cin >> n >> m;
		int i, j, level;
		int mid = (n >> 1) + 1;
		if (m == 1)
		{
			cout << mid << " " << mid << endl;
			continue;
		}

		for (i = 3, level = 2; ; i += 2, level ++)
			if (m <= i*i)	break;

		j = i * i - m;
		if (j < i-1)
		{
			r = mid - level + 1;
			c = mid + level - 1 - j;
		}
		else if (j < 2*(i-1))
		{
			r = mid - level + 1 + j - (i-1);
			c = mid - level + 1;
		}
		else if (j < 3*(i-1))
		{
			r = mid + level - 1;
			c = mid - level + 1 + j - 2*(i-1);
		}
		else
		{
			r = mid + level - 1 - (j - 3*(i-1));
			c = mid + level - 1;
		}
		cout << r << " " << c << endl;
	}
    
    return 0;    
}
