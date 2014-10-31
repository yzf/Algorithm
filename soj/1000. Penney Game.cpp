#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int t, n;
string line;
string str[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	cin >> t;
	while (t --) {
		cin >> n >> line;
		int len = line.length();
		
		map<string, int > smap;
		int i, j;
		for (i = 0; i < len - 2; i ++) {
			smap[ line.substr(i, 3) ] ++;
		}
		cout << n;
		for (i = 0; i < 8; i ++) {
			cout << " " << smap[ str[i] ] ;
		}
		cout << endl;
	}

	return 0;
}
