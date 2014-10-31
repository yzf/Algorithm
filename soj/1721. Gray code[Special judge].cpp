#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
bool flag[16], gray[16];

inline void print(int len)
{
    for (int ii = 0; ii < len; ii ++)
        cout << gray[ii] ;
    printf( "\n" );
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (scanf( "%d", &n ) && n != 0)
    {
        memset(flag, true, sizeof(flag));
        memset(gray, false, sizeof(gray));

        print(n);
        while (true)
        {
            int i;
            for (i = n-1; i >= 0; i --)
            {
                if (flag[i])
                {
                    gray[i] = !gray[i];
                    flag[i] = false;
                    print(n);

                    for (int j = i+1; j < n; j ++)
                        flag[j] = true;

                    break;
                }
            }
            if (i < 0)
                break;
        }
        printf( "\n" );
    }
    
    return 0;    
}
