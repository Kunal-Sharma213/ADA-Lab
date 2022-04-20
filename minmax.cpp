#include<iostream>
#include<climits>
#include<chrono>
#include<unistd.h>
using namespace std;
int qMin(int arr[], int l, int h) {
    if (h - l + 1 <= 1)
        return arr[l];
    int mid = (l + h) / 2;
    int m1 = INT_MAX, m2 = INT_MAX;
    m1 = min(m1, qMin(arr, 0, mid));
    m2  = min (m2, qMin(arr, mid + 1, h));
    return min(m1, m2);
}
int qMax(int arr[], int l, int h) {
    if (h - l + 1 <= 1)
        return arr[l];
    int mid = (l + h) / 2;
    int m1 = INT_MIN, m2 = INT_MIN;
    m1 = max(m1, qMax(arr, 0, mid));
    m2  = max (m2, qMax(arr, mid + 1, h));
    return max(m1, m2);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 20; i++ ) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        auto start = chrono::steady_clock::now();
        int ans1 = qMin(arr, 0 , n - 1);
        int ans2 = qMax(arr, 0 , n - 1);
        // cout << qMin(arr, 0, n - 1) << ",";
        // cout << qMax(arr, 0, n - 1);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';

    }
}