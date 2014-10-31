#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

bool flag;
int len;
string str;

int main()
{  
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
   
	while (cin >> str && str != "*")
	{
		flag = true;
		len = str.length();
		for (int i = 1; i < len; i ++)
		{
			set<string> strSet;
			for (int be = 0; be < len-i; be ++)
			{
				string temp;
				int cn = strSet.size();

				temp.push_back(str[be]);
				temp.push_back(str[be+i]);
				strSet.insert(temp);

				if (cn == strSet.size())//有相同时，size不会变 
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag)
			cout << str << " is surprising.\n";
		else
			cout << str << " is NOT surprising.\n";
	}

    return 0;  
} 
