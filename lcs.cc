#include<bits/stdc++.h>
using namespace std;
string s = "";
set<int> S1, S2;
int dp[50][50];
int lcs(string s1, string s2, int i, int j, int n1, int n2) {
    if (i == n1 || j == n2) return 0;
    if (s1[i] == s2[j]) {
        if (S1.find(i) == S1.end() && S2.find(j) == S2.end()) {
            s += s1[i];
            S1.insert(i);
            S2.insert(j);
        }
        return 1 + lcs(s1, s2, i + 1, j + 1, n1, n2);
    }
    return max(lcs(s1, s2, i + 1, j, n1, n2), lcs(s1, s2, i, j + 1, n1, n2));
}
int lcsMemo(string s1, string s2, int i, int j, int n1, int n2) {
    if (i == n1 || j == n2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j]) {
        if (S1.find(i) == S1.end() && S2.find(j) == S2.end()) {
            s += s1[i];
            S1.insert(i);
            S2.insert(j);
        }
        return 1 + lcsMemo(s1, s2, i + 1, j + 1, n1, n2);
    }
    return dp[i][j] = max(lcsMemo(s1, s2, i + 1, j, n1, n2), lcsMemo(s1, s2, i, j + 1, n1, n2));
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(dp, -1 , sizeof(dp));
    for (int i = 0; i < 20; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        auto start = chrono::steady_clock::now();
        int subLen = lcsMemo(s1, s2, 0 , 0, s1.size(), s2.size());
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << '\n';
    }
}