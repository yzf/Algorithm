#include <iostream>

using namespace std;

void insertion_sort(int arr[], int len) {
    for (int j = 1; j < len; ++ j) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            -- i;
        }
        arr[i + 1] = key;
    }
}

int main() {

    int a[6] = {31, 41, 59, 26, 41, 58};
    insertion_sort(a, 6);
    for (int i = 0; i < 6; ++ i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
