#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

string line;
int cases, a, b, c;
int len, index1, index2, index3;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> cases;
	getline(cin, line);
	while (cases --) {
		getline(cin, line);
		getline(cin, line);

		len = line.length();
		index1 = line.find('+');
		index2 = line.find('=');
		index3 = line.find('m');

		if (index3 < index1) {
			c = atoi(line.substr(index2+2, len-index2+2).c_str());
			b = atoi(line.substr(index1+2, index2-index1-3).c_str());
			a = c - b;
		}
		else if (index3 < index2) {
			a = atoi(line.substr(0, index1-1).c_str());
			c = atoi(line.substr(index2+2, len-index2+2).c_str());
			b = c - a;
		}
		else {
			a = atoi(line.substr(0, index1-1).c_str());
			b = atoi(line.substr(index1+2, index2-index1-3).c_str());
			c = a + b;
		}
		cout << a << " + " << b << " = " << c << endl;
	}

    return 0;
}
