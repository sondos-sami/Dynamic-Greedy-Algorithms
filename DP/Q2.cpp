#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int  Q2(const string &s) {
    int n = s.length();


    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {

        if (s[i - 1] != 'w' && s[i - 1] != 'm') {
            dp[i] = dp[i - 1];
        }


        if (i > 1 && s[i - 1] == 'u' && s[i - 2] == 'u') {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }


        if (i > 1 && s[i - 1] == 'n' && s[i - 2] == 'n') {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }

    return dp[n];
}


