#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1000010;

int n;
char pattern[N];
char ori[N];
int next[N];
// 计算next数组
void calNext()
{
    int lenO = strlen(pattern);
    int lenP = 0;
    int q = 0;
    memset(::next, 0, sizeof(int) * (lenO + 1));
    for (int i = 1; i <= lenO; ++ i) {
        lenP = i - 1;
        int p = i - 1;
        while (true) {
            if (q + 1 > lenP ||
                pattern[p + 1 - 1] != pattern[q + 1 - 1]) {
                if (q > 0)
                    q = ::next[q];
                else
                    break;
            }
            else {
                ++ q;
                break;
            }
        }
        ::next[i] = q;
    }
}
// 利用kmp算法的思想，统计子串出现的次数
int count()
{
    int lenO = strlen(ori);
    int lenP = strlen(pattern);
    int p = 0;
    int q = 0;
    int cnt = 0;
    while (p < lenO) {
        if (ori[p + 1 - 1] == pattern[q + 1 - 1]) {
            ++ p;
            ++ q;
        }
        else {
            if (q > 0)
                q = ::next[q];
            else
                ++ p;
        }
        if (q >= lenP) {
            ++ cnt;
            q = ::next[lenP];//匹配成功时，当匹配失败，继续匹配
        }
    }
    return cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    while (n --) {
        scanf("%s%s", pattern, ori);
        calNext();
        printf("%d\n", count());
    }
    return 0;
}
