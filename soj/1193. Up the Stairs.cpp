#include <iostream>
#include <algorithm>

using namespace std;

int t, person, penthouse, box, answer, stair, flag;
int a[1000];

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> t;
	while (t --)
	{
		cin >> person >> penthouse >> box;
	
	    for (int i = 0; i < person; i ++)
		{
			cin >> stair >> flag;
			if (flag == 1)
				a[i] = 3*penthouse - stair;
			else
				a[i] = penthouse + stair;
		}

		sort(a, a+person);

		int left = box % person;
		if (left != 0)
			answer = box/person*2*penthouse + a[box%person-1];
		else
			answer = (box/person - 1)*2*penthouse + a[person-1];
		cout << answer << endl;
	}

    return 0;
}
