#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int f(int n, int m) {
    int last = 0;
    for (int i = 2; i <= n; ++ i) {
        last = (last + m) % i;
    }
    return last;
}

int main() {
    freopen("input", "r", stdin);

    int n, m;
    while (scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        printf("%d\n", f(n, m) + 1);
    }

    return 0;
}
