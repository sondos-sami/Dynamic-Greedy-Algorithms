#include <bits/stdc++.h>
using namespace std;

int Q5(const vector<int>& A) {
    int N = A.size();

    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }


    return *max_element(dp.begin(), dp.end());
}