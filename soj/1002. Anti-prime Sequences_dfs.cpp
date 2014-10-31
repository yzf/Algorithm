#include <iostream>
#include <cstring>
#include <cstdio>
#include <numeric>

using namespace std;

const int MAX = 50000;

bool flag, isPrime[MAX+1], isUsed[1001];
int n, m, d;
int countTimes;
int prime[MAX+1], ans[1001];

void getPrime()
{
    int total = 0;
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= MAX; i ++)
    {
        if (isPrime[i])
            prime[total ++] = i;
        for (int j = 0; j < total && i*prime[j] <= MAX; j ++)
        {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

bool check(int len)
{
    int sum;
    if (len <= 1)
        return true;
    for (int i = 0; i < len; i ++)
    {
        sum = ans[i];
        if (i <= len-d)
        {
            for (int j = i+1; j-i+1 <= d; j ++)
            {
                sum += ans[j];
                if (isPrime[sum])
                    return false;
            }
        }
        else
        {
            for (int j = i+1; j < len; j ++)
            {
                sum += ans[j];
                if (isPrime[sum])
                    return false;
            }
        }
    }
    return true;
}

void dfs(int len)
{
    countTimes ++;
    if (countTimes > 3800)
        return ;
    if (flag)
        return ;
    if (!check(len))
        return ;
    if (len == m-n+1)
    {
        flag = true;
        return ;
    }
    for (int i = n; i <= m && !flag; i ++)
    {
        if (isUsed[i])
            continue;
        ans[len] = i;
        isUsed[i] = true;
        dfs(len+1);
        isUsed[i] = false;
    }
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

    getPrime();
    for (scanf("%d%d%d", &n, &m, &d); 
        n != 0 && m != 0 && d != 0; 
        scanf("%d%d%d", &n, &m, &d))
    {
        memset(isUsed, false, sizeof(isUsed));
        countTimes = 0;
        flag = false;
        dfs(0);
        if (flag)
        {
            printf( "%d", ans[0]);
            for (int i = 1; i < m-n+1; i ++)
                printf( ",%d", ans[i] );
            printf( "\n" );
        }
        else
            printf("No anti-prime sequence exists.\n");
    }

    return 0;
}
