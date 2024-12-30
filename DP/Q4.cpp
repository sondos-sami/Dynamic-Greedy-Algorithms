#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    int depth;
    int gold;
};

pair<int, vector<int>> calculateMaxGold(int t, int w, const vector<Treasure>& treasures) {
    int n = treasures.size();
    vector<int> dp(t + 1, 0);
    vector<vector<int>> choices(t + 1);

    for (int i = 0; i < n; ++i) {
        int total_time = 3 * w * treasures[i].depth;

        for (int j = t; j >= total_time; --j) {
            if (dp[j] < dp[j - total_time] + treasures[i].gold) {
                dp[j] = dp[j - total_time] + treasures[i].gold;
                choices[j] = choices[j - total_time];
                choices[j].push_back(i);
            }
        }
    }

    int max_gold = *max_element(dp.begin(), dp.end());
    int best_time = max_element(dp.begin(), dp.end()) - dp.begin();

    return {max_gold, choices[best_time]};
}
