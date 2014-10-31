#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int cases;
string preOrder, inOrder;
struct Interval {
    int preBe, preEn;
    int inBe, inEn;
} ;

bool check(Interval &x, int len)
{
    if (x.preBe < 0 || x.preBe >= len || x.preEn < 0 || x.preEn >= len ||
        x.inBe < 0 || x.inBe >= len || x.inEn < 0 || x.inEn >= len ||
        x.preBe > x.preEn || x.inBe > x.inEn )
        return false;
    return true;
}

string doit()
{
    string ans;
    Interval ne1, ne2, cur;
    queue<Interval> que;
    int len = preOrder.length();
    
    ne1.preBe = 0;         ne1.preEn = len-1;
    ne1.inBe = 0;         ne1.inEn = len-1;
    if (check(ne1, len))      que.push(ne1);
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        
        ans += preOrder[ cur.preBe ];
        for (int i = cur.inBe; i <= cur.inEn; i ++)
            if(preOrder[ cur.preBe ] == inOrder[i])
            {
                ne1.preBe = cur.preBe + 1;         ne1.preEn = cur.preBe + i - cur.inBe;
                ne1.inBe = cur.inBe;         ne1.inEn = i - 1;
                //cout << ne1.preBe << " " << ne1.preEn << " " << ne1.inBe << " " << ne1.inEn << endl;
                if (check(ne1, len))      que.push(ne1);
                
                ne2.preBe = ne1.preEn + 1;         ne2.preEn = cur.preEn;
                ne2.inBe = i + 1;         ne2.inEn = cur.inEn;
                //cout << ne2.preBe << " " << ne2.preEn << " " << ne2.inBe << " " << ne2.inEn << endl;
                if (check(ne2, len))      que.push(ne2);
                break;
            }
    }
    
    return ans;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    scanf( "%d", &cases );
    while (cases --)
    {
        cin >> preOrder >> inOrder;
        cout << doit() << endl;
    }
    
    return 0;
}
