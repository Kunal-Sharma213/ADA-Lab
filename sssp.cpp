#include<iostream>
#include<vector>
#include<set>
using namespace std;
void sssp(int mat[][60], int source, int n) {
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> distAndNode;
    distAndNode.insert({0, source});
    dist[source] = 0;
    while (!distAndNode.empty()) {
        auto it = distAndNode.begin();
        int nodeDistance = it->first;
        int node = it->second;
        distAndNode.erase(it);
        for (int i = 0; i < n; i++) {
            if (nodeDistance + mat[node][i] < dist[node]) {
                auto f = distAndNode.find({dist[node], node});
                if (f != distAndNode.end())
                    distAndNode.erase(f);
                dist[node] = nodeDistance + mat[node][i];
                distAndNode.insert({dist[node], node});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    for (int i = 0; i < 2; i++) {
        int n;
        // cout << "Enter number of nodes\n";
        cin >> n;
        int mat[60][60];
        memset(mat, -1, sizeof(mat));
        bool input = true;
        while (input) {
            // cout << "Enter the edges and the weight\n";
            int x, y, w;
            cin >> x >> y >> w;
            mat[x][y] = w;
            // cout << "Want to input more edges?(1/0)\n";
            cin >> input;
        }
        // cout << "Enter the source node\n";
        int source;
        cin >> source;
        // cout << n << ' ' << source << endl;
        auto start = chrono::steady_clock::now();
        sssp(mat, source, n);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << endl;
    }
}