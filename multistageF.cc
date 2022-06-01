#include<bits/stdc++.h>
using namespace std;
int mini_distance(vector<vector<int> > v){
    vector<int> dis(v.size(),INT_MAX);
    dis[dis.size()-1]=0;
    for (int i = dis.size()-2; i>=0; i--)
    {
        for (int j = i; j < dis.size(); j++)
        {
            if(v[i][j]==0){
                continue;
            }
            if(v[i][j]+dis[j]<dis[i]){
                dis[i]=v[i][j]+dis[j];
            }

        }
    }
    
    
    return dis[0];
    
}

int main(int argc, char const *argv[])
{
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


    cout<<"Minimum distance -> "<<mini_distance(gp);
       

    return 0;
}