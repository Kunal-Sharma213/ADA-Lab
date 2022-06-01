#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
int partition(int arr[], int l, int h){
    int pivot = arr[l], i = l, j = h;
    while(i < j){
        while(arr[i] >= pivot) i++;
        while(arr[j] < pivot) j--;

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}
void qSort(int arr[], int l , int h){
    if(l < h){
        if(ans == 2) {
            for(int i = n/4 + 1; i <(3*n)/4; i++) cout << arr[i] << " ";
            return;
        };
        int pos = partition(arr, l, h);
        if(pos == n / 4){
            ans++;
        }
        if(pos == (3*n)/4){
            ans++;
        }
        qSort(arr,l, pos);
        qSort(arr,pos+1,h);
    }
}
int main() {
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    qSort(arr, 0, n);
}