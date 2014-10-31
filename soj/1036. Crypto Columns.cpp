#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct pp {
       char c;
       int pre;
} ;

bool cmp( const pp &a, const pp &b )
{
    return a.c < b.c;
}

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
    string keyword, ciphertext;
    for (cin >> keyword; keyword != "THEEND"; cin >> keyword)
    {
        char answer[150][150];
        pp array[150];
        cin >> ciphertext;
        
        int len1 = keyword.length();
        int len2 = ciphertext.length();
        
        for (int i = 0; i < len1; i ++)
        {
            array[i].c = keyword[i];
            array[i].pre = i;
        }
        
        stable_sort(array, array+len1, cmp);
        
        for (int i = 0,k = 0; i < len1; i ++)
            for (int j = 0; j < len2/len1; j ++)
            {
                answer[j][array[i].pre] = ciphertext[k];
                k ++;
            }
        
        for (int j = 0; j < len2/len1; j ++)
            for (int i = 0; i < len1; i ++)
                cout << answer[j][i];
                
        cout << endl;
    }
    
    return 0;
}
