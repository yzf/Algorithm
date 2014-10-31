#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string str;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (cin >> str) {
		if (str == "#") {
			break;
		}

		string ans;
		int i;
		for (i = str.length()-1; i >= 0; i --) {
			if (str[i] == 'p') {
				ans += 'q';
			}
			else if (str[i] == 'q') {
				ans += 'p';
			}
			else if (str[i] == 'b') {
				ans += 'd';
			}
			else if (str[i] == 'd') {
				ans += 'b';
			}
			else if (str[i] == 'i' || str[i] == 'o' || str[i] == 'v' || str[i] == 'w' || str[i] == 'x') {
				ans += str[i];
			}
			else {
				break;
			}
		}
		if (i == -1) {
			cout << ans << endl;
		}
		else {
			cout << "INVALID\n";
		}
	}
	
	return 0;
}
