#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, sum, answer;
string result, str[120], temp = "ABCDE";
map<char, int> value;

inline int getValue(string &s)
{
    int v = 0;
    for (int i = 0; i < 4; i ++)
        for (int j = i+1; j < 5; j ++)
            if (value[s[i]] > value[s[j]])
                v ++;
    return v;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    for (cin >> n; n != 0; cin >> n)
    {
        for (int i = 0; i < n; i ++)
            cin >> str[i];
        
        answer = 1000000;
        do {

            sum = 0;
            for (int i = 0; i < 5; i ++)
                value[temp[i]] = i;
            
            for (int i = 0; i < n; i ++)
                sum += getValue(str[i]);
            
            if (sum < answer)
            {
                answer = sum;  
                result = temp;  
            }
            
        } while ( next_permutation(temp.begin(), temp.end()) );
        
        cout << result << " is the median ranking with value " << answer << ".\n";
    }
    
    return 0;
}
