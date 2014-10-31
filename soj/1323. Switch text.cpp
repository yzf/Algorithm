#include <iostream>
#include <string>

using namespace std;

string str1, str2;

bool checkEmpty(string &str) 
{  
    for(int i = 0; i < str.length(); i ++)  
        if(str[i] != ' ') return false;  
    return true;  
}

void doit(string &str)
{
    int len = str.length();
    if (len & 1)
    {
        for (int i = str.length()/2; i >= 0; i --)
            cout << str[i] ;
        for (int i = str.length()-1; i > str.length()/2; i --)
            cout << str[i] ;
    }
    else
    {
        for (int i = str.length()/2-1; i >= 0; i --)
            cout << str[i] ;
        for (int i = str.length()-1; i >= str.length()/2; i --)
            cout << str[i] ;
    } 
    cout << endl;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    while (true)
    {
        getline(cin, str1);
        getline(cin, str2);
        if (str2.length() > 0 && !checkEmpty(str2))
            doit(str2);
        if (str1.length() > 0 && !checkEmpty(str1))
            doit(str1);
        if (cin.eof())     break;
    }
    
    return 0;
}
