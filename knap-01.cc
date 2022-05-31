#include<bits/stdc++.h>
using namespace std;
int knapSackR(int n,int W, vector<int> weights, vector<int> profit)
{
 
    if (n == 0 || W == 0)
        return 0;
 
    if (weights[n - 1] > W)
        return knapSackR(n - 1,W, weights, profit);
    else
        return max(
            profit[n - 1]
                + knapSackR(n-1,W - weights[n - 1],
                           weights, profit),
            knapSackR(n-1,W, weights, profit));
}
int knapSackD(int n, int W, vector<int> weights, vector<int> profit)
{
    int dp[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

             else if (weights[i - 1] <= W)
                dp[i][j] = max(profit[i - 1] +
                                dp[i - 1][j - weights[i - 1]],
                                dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        
        }
    }
    return dp[n][W];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 50; i++){
    int n, W;
    cin >> n >> W;
    vector<int> weights, profit;

    for(int i = 0; i < n; i++){
        int w,p;
        cin >> w >> p;
        weights.push_back(w);
        profit.push_back(p);
    }

    auto start = chrono::steady_clock::now();
    int a1 = knapSackR(n,W,weights,profit);
    // int a2 = knapSackD(n,W,weights,profit);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';
    }
}