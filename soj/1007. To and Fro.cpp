#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    
    for (cin >> n; n != 0; cin >> n)
    {
        string str;
        char ans[100][100];
        cin >> str;
        int len = str.length();
        int row = len / n;
        int idx = 0;
        for (int i = 0; i < row; i ++)
        {
            if (i % 2 == 0)
                for (int j = idx, k = 0; j < idx + n; j ++)
                {
                    ans[i][k ++] = str[j];
                }
            else
                for (int j = idx + n - 1, k = 0; j >= idx; j --)
                {
                    ans[i][k ++] = str[j];
                }
            idx += n;
        }
        for (int j = 0; j < n; j ++)
            for (int i = 0; i < row; i ++)
                cout << ans[i][j];
        cout << endl;
    }
    
    //system( "pause" );
    return 0;
}
 
