#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int num;
int width, length;
int t;
int x[4], y[4];
int cn;
bool flag[40001];

enum Dire {
    HORIZONTAL,//水平 
    VERTICAL//竖直 
} ;
struct Line {
       int xbe, ybe;
       int xen, yen;
       Dire dire;
} line[400];

int solve(int xl, int yl, int xh, int yh)
{
    for (int i = 0; i < cn; i ++)
    {
        if (line[i].dire == HORIZONTAL && line[i].ybe > yl && line[i].ybe < yh)
        {//水平切 
            memset (flag, false, sizeof(flag));
            int h = line[i].ybe;
            //延长线段 
            for (int j = 0; j < cn; j ++)
            {
                if (line[j].dire == HORIZONTAL && line[j].ybe == h)
                    for (int k = line[j].xbe; k <= line[j].xen; k ++)
                        flag[k] = true;
            }
            //判断是否能切
            int count = 0;
            for (int j = xl; j <= xh; j ++)
                if (flag[j])
                   count ++;
            if (count == xh - xl + 1)
            {
                int t1 = solve(xl, h, xh, yh);
                int t2 = solve(xl, yl, xh, h);
                return (t1 > t2 ? t1 : t2);
            }
        }
        else if (line[i].dire == VERTICAL && line[i].xbe > xl && line[i].xbe < xh)
        {//竖直切 
            memset (flag, false, sizeof(flag));
            int w = line[i].xbe;
            //延长线段 
            for (int j = 0; j < cn; j ++)
            {
                if (line[j].dire == VERTICAL && line[j].xbe == w)
                    for (int k = line[j].ybe; k <= line[j].yen; k ++)
                        flag[k] = true;
            }
            //判断是否能切 
            int count = 0;
            for (int j = yl; j <= yh; j ++)
                if (flag[j])
                   count ++;
            if (count == yh - yl + 1)
            {
                int t1 = solve(xl, yl, w, yh);
                int t2 = solve(w, yl, xh, yh);
                return (t1 > t2 ? t1 : t2);
            }
        }
    }//不能切 
    return (xh - xl) * (yh - yl);
}

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
    cin >> num;
    while (num --)
    {
        cn = 0;
        cin >> width >> length;
        cin >> t;
        for (int i = 0; i < t; i ++)
        {
            cin >> x[2] >> y[2] >> x[1] >> y[1];
            x[0] = x[2];   y[0] = y[1];
            x[3] = x[1];   y[3] = y[2];
            //长方形的4条边 
            line[cn].dire = HORIZONTAL;
            line[cn].xbe = x[0];     line[cn].ybe = y[0];
            line[cn].xen = x[1];     line[cn ++].yen = y[1];
            
            line[cn].dire = VERTICAL;
            line[cn].xbe = x[2];     line[cn].ybe = y[2];
            line[cn].xen = x[0];     line[cn ++].yen = y[0];
            
            line[cn].dire = HORIZONTAL;
            line[cn].xbe = x[2];     line[cn].ybe = y[2];
            line[cn].xen = x[3];     line[cn ++].yen = y[3];
            
            line[cn].dire = VERTICAL;
            line[cn].xbe = x[3];     line[cn].ybe = y[3];
            line[cn].xen = x[1];     line[cn ++].yen = y[1];
        }
        cout << solve(0, 0, width, length) << endl;
    } 
    
    return 0;
}