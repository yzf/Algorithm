#include <iostream>
#include <string>
using namespace std;

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
    string str;
    
    for (cin >> str; str != "0"; cin >> str)
    {
        int temp;
        int tempCount = 0;
        int count = 1;
        
        for (int i = str.length() - 1; i >= 0; -- i)
        {
            if (str[i] > '2' || (str[i] == '2' && str[i+1] > '6'))
                tempCount = count;+
            else if (str[i] == '0')
            {
                tempCount = 0;
                -- i;     
            }
            else
            {
                temp = count;
                count = tempCount + count;
                tempCount = temp;
            }
        }
        
        cout << count << endl;
    } 
    
    return 0;
}
