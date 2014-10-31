#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int n;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    string number;
	cin >> n;
    for (int i = 1; i <= n; i ++)
    {
		cin >> number;
        int answer, temp;
        int array[9];
        int len = number.length();
        
        for (int i = 0; i < len; i ++)
		{
            array[i] = (number[i]-'0') < 4 ? (number[i] - '0') : (number[i] - '0' - 1);
			if ((number[i]-'0') < 2)
				array[i] = number[i] - '0';
			else if ((number[i]-'0') < 5)
				array[i] = number[i] - 1 - '0';
			else if ((number[i]-'0') < 8)
				array[i] = number[i] - 2 - '0';
			else
				array[i] = number[i] - 3 - '0'; 
		}
            
        answer = array[len-1];
        temp = 1;
        for (int i = len - 2; i >= 0; i --)
        {
            temp = temp * 7;
            answer += temp * array[i];
        }
        cout << number << ": " << answer << endl;
    }
    
    return 0;
}
