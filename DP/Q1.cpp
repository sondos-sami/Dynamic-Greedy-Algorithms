#include <bits/stdc++.h>

using namespace std;

int minDifference(vector<int>& coins) {
    int totalSum = accumulate(coins.begin(), coins.end(), 0);
    int n = coins.size();

    // Create a DP table to store results of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum / 2 + 1, false));

    // Initialize the first column as true (0 sum is possible with 0 elements)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum / 2; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Find the largest j such that dp[n][j] is true
    int j;
    for (j = totalSum / 2; j >= 0; j--) {
        if (dp[n][j]) break;
    }

    // The minimum difference will be totalSum - 2 * j
    return totalSum - 2 * j;
}
