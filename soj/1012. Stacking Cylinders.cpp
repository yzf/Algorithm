#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    int count;
    int i, k;
    double y, x[10];

    for(cin >> count; count != 0; cin >> count)
    {
        y = 1.0;
        for(i=0; i<count; i++)   
            cin >> x[i];
        
        sort(x, x+count);

        for(i=0; i<count-1; i++)
             y += sqrtf(4 - (x[1+i] - x[i])*(x[1+i] - x[i])/4);
        
        cout << fixed << setprecision(4) << (x[0] + x[count-1])/2
             << ' ' << y << endl;
    }

    return 0;
}
