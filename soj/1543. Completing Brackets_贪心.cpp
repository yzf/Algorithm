#include <iostream>
#include <string>

using namespace std;

int cn1, cn2;
string str, add;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    while (cin >> str)
    {
        cn1 = cn2 = 0;
        add.clear();
        for (int i = 0; i < str.length(); i ++)
        {
            str[i] == '[' ? cn1 ++ : cn2 ++;
            if (cn1 < cn2)     
            {
                cout << '[' ;
                cn1 ++;
            }
        }
        for (int i = 0; i < cn1-cn2; i ++)
            add += ']';
        
        cout << str << add << endl;
    }
    
    return 0;
}
