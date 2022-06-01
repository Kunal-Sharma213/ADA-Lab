#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<bool>> mp;
int mS(vector<vector<int>> gp, int i, int dTN, vector<bool> &vis){
    if(i == gp.size() - 1){
        mp[dTN] = vis;
        return dTN;
    }
    vis[i] = true;
    int ans = INT_MAX;
    for(int j = i + 1; j < gp.size(); j++){
        if(gp[i][j]){
            vis[j] = true; 
            ans = min(ans, mS(gp, j, dTN + gp[i][j], vis));
            vis[j] = false;
        }
    }
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp;
    gp.resize(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        gp[x][y] = w;
        gp[y][x] = w;
    }

    vector<bool> x(n,false);
    // int res = mS(gp, 0,0, x);
    // for(auto x: mp){
    //     if(x.first == res){
    //         for(auto y: x.second) cout << y << " ";
    //     }
    // }

    cout << "Minimum distance -> "<< mS(gp,0,0,x);
}