#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

using namespace std;

void merge_sort(int *arr, int len) {
    if (len == 1) {
        return ;
    }
    else if (len == 2) {
        if (arr[0] > arr[1]) {
            swap(arr[0], arr[1]);
        }
    }
    else {
        int mid = len / 2;
        merge_sort(arr, mid);
        merge_sort(arr + mid, len - mid);
        int *tmp = new int[mid];
        memcpy(tmp, arr, mid * sizeof(int));
        int i = 0, j = mid;
        int k = 0;
        while (i < mid && j < len) {
            if (tmp[i] < arr[j]) {
                arr[k ++] = tmp[i ++]; 
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
    
    int a[8];
    for (int i = 0; i < 8; ++ i) {
        cin >> a[i];
    }
    merge_sort(a, 8);
    for (int i = 0; i < 8; ++ i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
