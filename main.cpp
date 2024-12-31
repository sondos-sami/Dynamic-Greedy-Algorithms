#include <iostream>
#include<vector>
#include "DP/Q1.cpp"
#include "DP/Q2.cpp"
#include "DP/Q3.cpp"
#include "DP/Q4.cpp"
#include "DP/Q5.cpp"
#include "Greedy/Q1.cpp"
#include "Greedy/Q2.cpp"
#include "Greedy/Q3.cpp"
#include "Greedy/Q4.cpp"
#include "Greedy/Q5.cpp"
using namespace std;


int main() {
    int choice;

    while (true) {
        cout << "\nSelect a problem to execute:" << endl;
        cout << "Dynamic Programming Problems:" << endl;
        cout << "  1. Q1 - Dynamic Programming Problem 1" << endl;
        cout << "  2. Q2 - Dynamic Programming Problem 2" << endl;
        cout << "  3. Q3 - Dynamic Programming Problem 3" << endl;
        cout << "  4. Q4 - Dynamic Programming Problem 4" << endl;
        cout << "  5. Q5 - Dynamic Programming Problem 5" << endl;
        cout << "Greedy Problems:" << endl;
        cout << "  6. Q1 - Greedy Problem 1" << endl;
        cout << "  7. Q2 - Greedy Problem 2" << endl;
        cout << "  8. Q3 - Greedy Problem 3" << endl;
        cout << "  9. Q4 - Greedy Problem 4" << endl;
        cout << " 10. Q5 - Greedy Problem 5" << endl;
        cout << " 11. Exit" << endl;
        cout << "Enter the problem number (1-11): ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int t;
                    cin >> t; // Number of test cases

                    while (t--) {
                        int n;
                        cin >> n; // Number of coins
                        vector<int> coins(n);

                        for (int i = 0; i < n; i++) {
                            cin >> coins[i]; // Values of the coins
                        }

                        cout << minDifference(coins) << endl; // Output the minimum difference
                    }

                    return 0;
                }
                break;
            case 2:
                cout << "You selected Q2 - Dynamic Programming Problem 2" << endl;
                {
                    string s;
                    cout<<"enter your text";
                    cin >> s;


                    if (s.find('w') != string::npos || s.find('m') != string::npos) {
                        cout << 0 << endl;
                        return 0;
                    }

                    cout << Q2(s) << endl;
                }
                break;
            case 3:
                cout << "You selected Q3 - Dynamic Programming Problem 3" << endl;
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
                break;
            case 4:
              {
                    ios::sync_with_stdio(false);
                    cin.tie(nullptr);

                    bool first_case = true;
                    int t, w;

                    while (cin >> t >> w) {
                        if (!first_case) cout << "\n";
                        first_case = false;

                        int n;
                        cin >> n;

                        vector<Treasure> treasures(n);
                        for (int i = 0; i < n; ++i) {
                            cin >> treasures[i].depth >> treasures[i].gold;
                        }

                        pair<int, vector<int>> result = calculateMaxGold(t, w, treasures);
                        int max_gold = result.first;
                        vector<int> choice_indices = result.second;

                        cout << max_gold << "\n";
                        cout << choice_indices.size() << "\n";
                        for (int index : choice_indices) {
                            cout << treasures[index].depth << " " << treasures[index].gold << endl;
                        }
                    }

                }
                break;
            case 5:
            {
                int N;
                cout << "Enter the size of the array: ";
                cin >> N;
                vector<int> A(N);
                cout << "Enter the elements of the array: ";
                for (int i = 0; i < N; i++) {
                    cin >> A[i];
                }
                int result = Q5(A);
                cout << "Result: " << result << endl;
            }
                break;
            case 6:
               {
                vector<int> g1 = {1, 2, 3};
                vector<int> s1 = {1, 1};
                cout << "Example 1: " << findContentChildren(g1, s1) << endl;

                vector<int> g2 = {1, 2};
                vector<int> s2 = {1, 2, 3};
                cout << "Example 2: " << findContentChildren(g2, s2) << endl;
        }
                break;
            case 7:
               {
                TaskScheduler scheduler;
                vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
                int n = 2;
                cout << scheduler.leastInterval(tasks, n) << endl; // Output: 8
                return 0;
            }
                break;
            case 8:
                cout << "You selected Q3 - Greedy Problem 3" << endl;
                solveGraphProblem();
                break;
            case 9:
                cout << "You selected Q4 - Greedy Problem 4" << endl;
                break;
            case 10:
                {
                ios_base::sync_with_stdio(false);
                cin.tie(0);
                cin >> num_nodes >> num_edges;

                KruskalAlgorithm kruskal(num_nodes);
                for (int i = 1; i <= num_edges; ++i) {
                    int u, v, weight;
                    cin >> u >> v >> weight;
                    kruskal.add_edge(u, v, weight);
                }

                kruskal.MST();
                dfs(1, 0);

                for (int i = 0; i < max_nodes * 2; ++i) {
                    ll adjustment = weight_count[i] / 2;
                    weight_count[i] -= (adjustment * 2);
                    result[i] = weight_count[i];
                    weight_count[i + 1] += adjustment;
                }

                bool non_zero_found = false;
                for (int i = 2 * max_nodes - 1; i >= 0; --i) {
                    if (!result[i]) {
                        if (non_zero_found) cout << result[i];
                    } else {
                        non_zero_found = true;
                        cout << result[i];
                    }
                }

                cout << '\n';
            }
                break;
            case 11:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 11." << endl;
                break;
        }
    }

}
