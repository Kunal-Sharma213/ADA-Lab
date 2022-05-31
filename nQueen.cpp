#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
bool check(int k, int i, vector<int> &place) {
    for (int j = 1; j <= k - 1 ; j++) {
        if (i == place[j] || abs(k - j) == abs(place[j] - i))
            return false;
    }

    return true;
}

void nQueen(int k, vector<int> & place) {

    for (int i = 1; i <= n; i++) {
        if (check(k, i, place)) {
            place[k] = i;
            if (k == n ) {
                return;
                // ans++;
                // for(const auto &x: place){
                //     cout << x << " ";
                // }
                // cout << '\n';
            } else {
                nQueen(k + 1, place);
            }
        }
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 20; i++) {
        cin >> n;
        vector<int> place(n + 1 );
        auto start = chrono::steady_clock::now();
        nQueen(1, place);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';
    }
}