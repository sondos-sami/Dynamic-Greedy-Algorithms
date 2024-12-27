//
// Created by Dell on 24/12/2024.
//
// assignment 3 algo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Maya Mohamed
// id: 20220271 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; // Number of instances
    cin >> n;

    while (n--) {
        int k, m; // Maximum weight and number of bags
        cin >> k >> m;

        vector<int> weights(m);
        vector<int> values(m);

        // Input weights and values
        for (int i = 0; i < m; i++) {
            cin >> weights[i] >> values[i];
        }

        // DP table: Rows for bags, Columns for weight limits
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

        // Fill DP table
        for (int i = 1; i <= m; i++) { // Loop over bags
            for (int j = 1; j <= k; j++) { // Loop over weight limits
                if (weights[i - 1] <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Output the result for this instance
        cout << "Hey stupid robber, you can get " << dp[m][k] << "." << endl;
    }

    return 0;
}
