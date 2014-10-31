#include <iostream>
#include <numeric>
#include <string.h>

using namespace std;

const int MAXSIZE = 101;
int n, m, l;
int m1[MAXSIZE][MAXSIZE];
int m2[MAXSIZE][MAXSIZE];
int temp[MAXSIZE][MAXSIZE];

bool Init()
{
    if(scanf("%d%d%d", &n, &m, &l) != 3)
        return false;
    else
    {
        int i;
        int p1, p2;
        memset(m1, 0, sizeof(m1));
        memset(m2, 0, sizeof(m2));
        for(i=0; i<m; i++)
        {
            scanf("%d%d", &p1, &p2);
            p1--, p2--;
            m1[p1][p2] = m2[p1][p2] = 1;
        }
        return true;
    }
}

void Mul1()//当前N次方矩阵的平方
{
    int i, k, l;
    memset(temp, 0, sizeof(temp));
    for(i=0; i<n; i++)
    {
        for(k=0; k<n; k++)
        {
            for(l=0; l<n; l++)
            {
                temp[i][k] += m2[i][l] * m2[l][k];
            }
        }
    }
    memcpy(m2, temp, sizeof(temp));
}

void Mul2()//当前矩阵乘以初始矩阵
{
    int i, k, l;
    memset(temp, 0, sizeof(temp));
    for(i=0; i<n; i++)
    {
        for(k=0; k<n; k++)
        {
            for(l=0; l<n; l++)
            {
                temp[i][k] += m1[i][l] * m2[l][k];
            }
        }
    }
    memcpy(m1, temp, sizeof(temp));
}

void Compute()
{
    int times = l - 1;
    while(times > 0)
    {
        if(times & 1)
            Mul2();
        Mul1();
        times >>= 1;
    }
}

int main() 
{
    int qs, begin, end;
    while(Init())
    {
        Compute();
        scanf("%d", &qs);
        while(qs--)
        {
            scanf("%d%d", &begin, &end);
            printf("%d\n", m1[begin-1][end-1]);
        }
    }
    return 0;
}
