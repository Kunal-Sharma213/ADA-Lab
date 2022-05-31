#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weights, profit;

    for(int i = 0; i < n; i++){
        int w,p;
        cin >> w >> p;
        weights.push_back(w);
        profit.push_back(p);
    }

    int dp[n + 1][W+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = max(dp[i-1][j], profit[i] + dp[i-1][j - weights[i]]);
        }
    }

    cout << dp[n][W];
}