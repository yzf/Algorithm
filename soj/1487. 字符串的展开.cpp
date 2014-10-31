#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int p1, p2, p3, cn;
string str;

char toUpper(char c)
{
	if (c >= 'a' && c <= 'z')	return c + 'A' - 'a';
	return c;
}

bool isSame(char c1, char c2)
{
	if (c1 == c2)
		return false;
	if ((c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z') 
	 || (c1 >= '0' && c1 <= '9' && c2 >= '0' && c2 <= '9'))
		return true;
	return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cn = 1;
	while (cin >> p1 >> p2 >> p3)
	{
		if (cn ++ != 1)	cout << endl;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i ++)
		{
			if (str[i] != '-')	
			{
				cout << str[i] ;
				continue;
			}
			else if (!isSame(str[i-1], str[i+1]))
			{
				cout << str[i] ;
				continue;
			}

			switch(p1) {
			case 1:
				switch(p3) {
				case 1:
					if (str[i-1] >= str[i+1])
					{
						cout << str[i] ;
						break;
					}
					for (char j = str[i-1]+1; j < str[i+1]; j ++)
						for (int k = 0; k < p2; k ++)
							cout << j ;
					break;

				case 2:
					if (str[i-1] >= str[i+1])
					{
						cout << str[i] ;
						break;
					}
					for (char j = str[i+1]-1; j > str[i-1]; j --)
						for (int k = 0; k < p2; k ++)
							cout << j ;
					break;
				}
				break;

			case 2:
				switch(p3) {
				case 1:
					if (str[i-1] >= str[i+1])
					{
						cout << str[i] ;
						break;
					}
					for (char j = str[i-1]+1; j < str[i+1]; j ++)
						for (int k = 0; k < p2; k ++)
							cout << toUpper(j) ;
					break;

				case 2:
					if (str[i-1] >= str[i+1])
					{
						cout << str[i] ;
						break;
					}
					for (char j = str[i+1]-1; j > str[i-1]; j --)
						for (int k = 0; k < p2; k ++)
							cout << toUpper(j) ;
					break;
				}
				break;

			case 3:
				switch(p3) {
				case 1:
					if (str[i-1] >= str[i+1])
					{
						cout << str[i] ;
						break;
					}
					for (char j = str[i-1]+1; j < str[i+1]; j ++)
						for (int k = 0; k < p2; k ++)
							cout << '*' ;
					break;

				case 2:
					if (str[i-1] >= str[i+1])
					{
						cout << str[i] ;
						break;
					}
					for (char j = str[i+1]-1; j > str[i-1]; j --)
						for (int k = 0; k < p2; k ++)
							cout << '*' ;
					break;
				}
				break;
			} 
		}
		cout << endl;
	}

    return 0;    
}
