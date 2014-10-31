#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    string number;
    for (cin >> number; number != "0"; cin >> number)
    {
        int answer, temp;
        int array[9];
        int len = number.length();
        
        for (int i = 0; i < len; i ++)
            array[i] = (number[i]-'0') < 4 ? (number[i] - '0') : (number[i] - '0' - 1);
            
        answer = array[len-1];
        temp = 1;
        for (int i = len - 2; i >= 0; i --)
        {
            temp = temp * 9;
            answer += temp * array[i];
        }
        cout << number << ": " << answer << endl;
    }
    
    return 0;
}
