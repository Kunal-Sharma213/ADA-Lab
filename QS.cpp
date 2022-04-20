#include<iostream>
#include<vector>
#include<chrono>
#include<unistd.h>
using namespace std;
int partition(vector<int>&a, int l, int h) {
    int pivot = a[l];
    int i = l, j = h;
    while (i < j) {
        while (a[i] <= pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}
void quickSort(vector<int>&a, int l, int h) {
    if (l < h) {
        int index = partition(a, l, h);
        quickSort(a, l, index);
        quickSort(a, index + 1, h);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 1; i < 20; i++) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        v.push_back(INT_MAX);
        auto start = chrono::steady_clock::now();
        quickSort(v, 0, n);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << endl;
    }
    // for (int i = 0; i < n; i++) cout << v[i] << ' ';
}