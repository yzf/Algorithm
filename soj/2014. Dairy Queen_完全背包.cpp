#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, c, a[10], cn[400];
//完全背包，用dp实现 
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    memset(cn, 0, sizeof(cn));
    cn[0] = 1;
    
    cin >> n >> c;
    for (int i = 0; i < c; i ++)
        cin >> a[i];
     
    for (int i = 0; i < c; i ++)
    {
        for (int j = 0; j <= n-a[i]; j ++)
        {
            if (cn[j] > 0)
            {
                cn[j + a[i]] += cn[j];
            }
        }
    }
    
    cout << cn[n] << endl;
        
    return 0;
}
