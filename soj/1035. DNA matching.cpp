#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string cmp(string &str)
{
	string result;
	for (int i = 0; i < str.length(); i ++)
	{
		switch(str[i]) {
		case('A') : result += 'T'; break;
		case('T') : result += 'A'; break;
		case('C') : result += 'G'; break;
		case('G') : result += 'C'; break;
		}
	}
	return result;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	int t, n, answer;
	string str;
	vector<string> dna;
	vector<string>::iterator it;

	cin >> t;
	while (t --)
	{
		answer = 0;
		dna.clear();

		cin >> n;
		for (int i = 0; i < n; i ++)
		{
			cin >> str;
			it = find(dna.begin(), dna.end(), cmp(str));
			if (it != dna.end())
			{
				answer ++;
				dna.erase(it);
			}
			else
				dna.push_back(str);
		}
		cout << answer << endl;
	}
    
    return 0;
}
