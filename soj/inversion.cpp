#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

using namespace std;

void inversion(int *arr, int len, int &count) {
    if (len == 1) {
        return ;
    }
    else if (len == 2) {
        if (arr[0] <= arr[1]) {
            swap(arr[0], arr[1]);
        }
        else {
            ++ count;
        }
    }
    else {
        int mid = len / 2;
        inversion(arr, mid, count);
        inversion(arr + mid, len - mid, count);
        int *tmp = new int[mid];
        memcpy(tmp, arr, mid * sizeof(int));
        int i = 0, j = mid;
        int k = 0;
        while (i < mid && j < len) {
            if (tmp[i] > arr[j]) {
                arr[k ++] = tmp[i ++]; 
                count += len - j;
            }
            else {
                arr[k ++] = arr[j ++];
            }
        }
        memcpy(arr + k, tmp + i, (mid - i) * sizeof(int));
    }
}

int main() {
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    
    int a[5];
    int count = 0;
    for (int i = 0; i < 5; ++ i) {
        cin >> a[i];
    }
    inversion(a, 5, count);
    cout << count << endl;

    return 0;
}
