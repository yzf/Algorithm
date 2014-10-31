#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int Max = 10000;

bool check(int *data, int len) {
    if (0 == len) {
        return true;
    }
    int root = data[len - 1];
    int i = 0;
    while (i < len - 1) {
        if (data[i] > root) {
            break;
        }
        ++ i;
    }
    int j = i;
    while (j < len - 1) {
        if (data[j] < root) {
            break;
        }
        ++ j;
    }
    return j != len - 1 ? 
            false : check(data, i) && check(data + i, len - 1 - i);
}

int main() {
    //freopen("input", "r", stdin);

    int n;
    int data[Max];
    while (cin >> n) {
        for (int i = 0; i < n; ++ i) {
            cin >> data[i];
        }

        if (check(data, n)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
