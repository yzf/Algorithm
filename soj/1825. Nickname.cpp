#include <iostream>
#include <string>
#include <map>

using namespace std;

int cases, n;
string name;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	cin >> cases;
	while (cases --)
	{
		map< string, int > nameCn;
		map< string, int >::iterator it;
		cin >> n;
		while (n --)
		{
			cin >> name;
			for (int i = 0; i < name.length(); i ++)
				if (name[i] >= 'A' && name[i] <= 'Z')
					name[i] = name[i] - 'A' + 'a';
			nameCn[name] ++;
		}
		
		for (it = nameCn.begin(); it != nameCn.end(); it ++)
			cout << it->first << " " << it->second << endl;
		cout << endl;
	}

    return 0;
}

