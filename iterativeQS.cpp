#include<iostream>
#include<chrono>
#include<unistd.h>
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int h) {
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSort(int A[], int l, int h) {
    if (l < h) {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 20; i++) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        auto start = chrono::steady_clock::now();

        quickSort(arr, 0, n - 1);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << endl;
    }

    // for (int i = 0; i < n; i++) {
    // 	cout << arr[i] << " ";
    // }
}
