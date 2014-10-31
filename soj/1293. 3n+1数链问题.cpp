#include <iostream>
#include <vector>

using namespace std;

vector<int> l;

void doit(int n)
{
    l.push_back(n);
    int temp;
    if (n == 1)
        return ;
    else if (n % 2 == 1)
        doit(3*n+1);
    else if (n % 2 == 0)
        doit(n/2);  
}

int main()
{
    
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
    int i, j, ans = 0;
    cin >> i >> j;
    
    for (int ii = i; ii <= j; ii ++)
    {
        l.clear();
        doit(ii);
        if (l.size() > ans)
            ans = l.size();
    }
    cout << ans << endl;
    
    return 0;
}
