#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int Max = 100000;
/*
 * dp[i]表示以i为开始的子向量的和的最大值
 * dp[i] = data[i] ( dp[i + 1] <= 0 )
 *          dp[i + 1] + data[i] ( dp[i + 1] > 0 )
 */
int main() {
    freopen("input", "r", stdin);

    int n;
    int data[Max];
    int dp[Max];
    int end[Max];

    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &data[i]);
        }
        
        int maxSum = data[n - 1];
        dp[n - 1] = data[n - 1];
        end[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; -- i) {
            if (dp[i + 1] <= 0) {
                dp[i] = data[i];
                end[i] = i;
            }
            else {
                dp[i] = dp[i + 1] + data[i];
                end[i] = end[i + 1];
            }
            maxSum = dp[i] > maxSum ? dp[i] : maxSum;
        }
        for (int i = 0; i < n; ++ i) {
            if (dp[i] == maxSum) {
                printf("%d %d %d\n", maxSum, i, end[i]);
                break;
            }
        }
    }

    return 0;
}
