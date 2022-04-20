#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<unistd.h>
using namespace std;

bool sortByProfit(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
bool sortByWeight(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
int calcProfit(vector<pair<int, int> > weightAndProfit, int maxWeight, bool profitPerUnitWeight) {
    int profit = 0, weight = maxWeight;
    vector<pair<double, int>> fractionAndProfit;
    for (auto x : weightAndProfit) {
        if (weight - x.first > 0) {
            if (profitPerUnitWeight)
                fractionAndProfit.push_back({1, x.second * x.first});
            else
                fractionAndProfit.push_back({1, x.second});
            weight = weight - x.first;
        } else {
            if (profitPerUnitWeight)
                fractionAndProfit.push_back({weight / (double)x.first, x.second * x.first});
            else
                fractionAndProfit.push_back({weight / (double)x.first, x.second});
            break;
        }
    }
    // cout << "--------\n";
    for (auto x : fractionAndProfit) {
        // cout << x.first << " " << x.second << endl;
        profit += (x.first * x.second);
    }
    return profit;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 50; i++) {
        int n, W;
        // cout << "Enter number of items\n";
        cin >> n;
        vector<pair<int, int>> weightAndProfit;
        // cout << "Enter the max weight the bag can hold\n";
        cin >> W;
        // cout << "Enter the weight and profit of individual item\n";
        for (int i = 0; i < n; i++) {
            int w, p;
            cin >> w >> p;
            weightAndProfit.push_back({w, p});
        }
        auto start = chrono::steady_clock::now();
        // sort(weightAndProfit.begin(), weightAndProfit.end(), sortByProfit);
        // cout << "Profit generated when we sort by Profit -> " << calcProfit(weightAndProfit, W, false) << endl;
        // sort(weightAndProfit.begin(), weightAndProfit.end(), sortByProfit);
        // sort(weightAndProfit.begin(), weightAndProfit.end(), sortByWeight);
        for (int i = 0; i < weightAndProfit.size(); i++) {
            weightAndProfit[i].second = weightAndProfit[i].second / weightAndProfit[i].first;
        }
        sort(weightAndProfit.begin(), weightAndProfit.end(), sortByProfit);
        calcProfit(weightAndProfit, W, false);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << endl;
        // cout << calcProfit(weightAndProfit, W, false) << ' ' << i + 1 << ' ' << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "," << endl;
    }
    // sort(weightAndProfit.begin(), weightAndProfit.end(), sortByWeight);
    // // cout<<"\nProfit generated when we sort by Weight -> " <<calcProfit(weightAndProfit, W, false);
    // for (int i = 0; i < weightAndProfit.size(); i++) {
    //     weightAndProfit[i].second = weightAndProfit[i].second / weightAndProfit[i].first;
    // }
    // sort(weightAndProfit.begin(), weightAndProfit.end(), sortByProfit);
    // cout << "\nProfit generated when we sort by Profit per unit weight -> " << calcProfit(weightAndProfit, W, true) << '\n';
    // for(auto x: weightAndProfit){
    //     cout<<x.first << " "<< x.second<<endl;
    // }
}

