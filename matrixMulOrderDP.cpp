#include<iostream>
#include<chrono>
#include<unistd.h>
using namespace std;
int s[100][100];
void printOrder( int i, int j) {
    if (i == j) cout << i;
    else {
        cout << "(";
        printOrder(i , s[i][j]);
        printOrder( s[i][j] + 1, j);
        cout << ")";
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 20; i++) {
        int n;
        cin >> n;
        int n_order = n + 1;
        // cout<<n_order<<endl;
        int *order = new int[n_order];
        for (int i = 0; i < n_order; i++) cin >> order[i];
        int m[n_order][n_order];
        for (int i = 0; i < n_order; i++) {
            m[i][i] = 0;
        }
        for (int i = 0; i < n_order; i++) {
            for (int j = 0; j < n_order; j++) {
                if (j < i)
                    m[i][j] = -1, s[i][j] = -1;
                if (j > i)
                    m[i][j] = INT_MAX;
            }
        }
        auto start = chrono::steady_clock::now();
        for (int l = 1; l < n_order; l++) {
            for (int i = 1; i < n_order - l + 1; i++) {
                int j = i + l - 1 ;
                for (int k  = i; k < j; k++) {
                    int inter = m[i][k] + m[k + 1][j] + (order[i - 1] * order[k] * order[j]);
                    if (inter < m[i][j]) {
                        m[i][j] = inter;
                        s[i][j] = k;
                    }
                }
            }
        }
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << endl;
        // cout << "M Matrix ------\n";
        // for (int i = 1; i < n_order; i++) {
        //     for (int j = 1; j < n_order; j++) {
        //         if (j >= i)
        //             cout << m[i][j] << '\t';
        //     }
        //     cout << '\n';
        // }
        // cout << "S Matrix ------ \n";
        // for (int i = 1; i < n_order; i++) {
        //     for (int j = 1; j < n_order; j++) {
        //         if (j >= i)
        //             cout << s[i][j] << '\t';
        //     }
        //     cout << '\n';
        // }

        // cout << "Printing the order - \n";
        // printOrder( 1 , n);
    }
}