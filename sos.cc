#include<bits/stdc++.h>
using namespace std;
void subsetSum(vector<bool> &x, int s, int r, int k, int sum, int arr[]){
    if(k >= x.size()) return;
    x[k] = true;

    if(s + arr[k] == sum){
        // for(int i = 0; i < x.size(); i++){
        //     cout << x[i] << " ";
        // }
        // cout << '\n';
        x[k] = 0;
    }
    else if(s + arr[k] + arr[k+1] <= sum){
        subsetSum(x,s+arr[k], r - arr[k], k+1, sum, arr);
    }

    if(s + r  - arr[k] >= sum && s + arr[k+1] <= sum){
        x[k] = false;
        subsetSum(x,s,r-arr[k],k+1,sum,arr);
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < 50; i++){
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    int totalSum = 0;
    for(int i=0; i<n; i++) cin >> arr[i], totalSum += arr[i];
    vector<bool> x(n,false);
    auto start = chrono::steady_clock::now();
    sort(arr, arr+n);
    int s = 0, r = 0;
    subsetSum(x,s,totalSum,0,sum,arr);
     auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';
   
    }
}