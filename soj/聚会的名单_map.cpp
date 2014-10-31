#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
string name;
map<string, int> cn;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

    cin >> n;
    while (n --)
    {
        cin >> name;
        cn[name] ++;
    }
    cin >> m;
    while (m --)
    {
        cin >> name;
        cout << cn[name] << endl;
    }
    
	return 0;
}
