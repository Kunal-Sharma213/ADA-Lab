#include <climits>
#include <iostream>
#include<chrono>
#include<unistd.h>
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k = 4;
    for (int i = 0; i < 20; i++) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        auto start = chrono::steady_clock::now();
        kthSmallest(arr, 0, n - 1, k);
       
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';
    }
}
