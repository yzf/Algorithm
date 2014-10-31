#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    int n;
    for (cin >> n; n != 0; cin >> n)
    {
        string ID[20], IP[20];
        bool visit[20];
        map<string, string> save;
        memset( visit, false, sizeof(visit) );
        for (int i = 0; i < n; i ++)
            cin >> ID[i] >> IP[i]; 
            
        for (int i = 0; i < n; i ++)
            if (visit[i] == false)
            {
                int j;
                for (j = i + 1; j < n; j ++)
                    if (IP[j] == IP[i])
                        break;
                visit[i] = visit[j] = true;
                save.insert( make_pair(ID[i], ID[j]) );
            }
        
        for (map<string, string>::iterator it = save.begin(); it != save.end(); it ++) 
            cout << it->second << " is the MaJia of " << it->first << endl;

        cout << endl;
    }
    
    return 0;
}
