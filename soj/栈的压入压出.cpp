#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

const int Max = 100000;
int n;
int pushOrder[Max];
int popOrder[Max];

int main() {
    //freopen("input", "r", stdin);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &pushOrder[i]);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &popOrder[i]);
        }
        stack<int> st;
        int pushId = 0;
        int popId = 0;
        while (pushId < n || popId < n) {
            if (! st.empty() && st.top() == popOrder[popId]) {
                st.pop();
                ++ popId;
            }
            else if (pushOrder[pushId] == popOrder[popId]) {
                ++ pushId;
                ++ popId;
            }
            else {
                st.push(pushOrder[pushId]);
                ++ pushId;
            }
        }
        if (st.empty()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
