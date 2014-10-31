#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int Max = 1000000;

int n;

int main() {
    freopen("input", "r", stdin);

    while (scanf("%d", &n) != EOF && n >= 0) {
        bool flag = false;
        int l = 1;
        int r = 2;
        int half = (n + 1) >> 1;
        int target = 2 * n;
        while (l < half) {
            int sum = (r - l + 1) * (l + r);
            if (sum == target) {
                flag = true;
                for (int i = l; i < r; ++ i) {
                    printf("%d ", i);
                }
                printf("%d\n", r);
                ++ l;
            }
            else if (sum < target) {
                ++ r;
            }
            else {
                ++ l;
            }
        }
        if (! flag) {
            printf("Pity!\n");
        }
        printf("#\n");
    }

    return 0;
}
