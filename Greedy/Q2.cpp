#include <bits/stdc++.h>

using namespace std;

class TaskScheduler {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        unordered_map<char, int> taskCounts;
        for (char task : tasks) {
            taskCounts[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& pair : taskCounts) {
            maxHeap.push(pair.second);
        }

        int intervals = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            while (cycle > 0 && !maxHeap.empty()) {
                int top = maxHeap.top();
                maxHeap.pop();
                if (top > 1) {
                    temp.push_back(top - 1);
                }
                intervals++;
                cycle--;
            }

            for (int t : temp) {
                maxHeap.push(t);
            }

            if (maxHeap.empty()) break;
            intervals += cycle; // Add idle intervals
        }

        return intervals;
    }
};
