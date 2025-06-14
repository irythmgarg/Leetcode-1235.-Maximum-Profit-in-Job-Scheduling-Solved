class Solution {
public:
    int dp[60000];  // DP array to memoize results, initialized to -1

    // Finds the next index where the job can be scheduled without conflict
    int getnextindex(vector<pair<int, pair<int, int>>>& p, int i, int currentend) {
        for (int r = i; r < p.size(); r++) {
            if (p[r].first >= currentend)  // If the next job starts after or at the end of the current job
                return r;
        }
        return -1;  // No non-overlapping job found
    }

    // Recursively calculates the maximum profit from index i onwards
    int profit(vector<pair<int, pair<int, int>>>& p, int i) {
        if (i >= p.size()) return 0;  // Base case: no jobs left
        if (dp[i] != -1) return dp[i];  // Return memoized result

        auto now = p[i];
        int take = now.second.second;  // Profit if we take the current job

        // Find the next job index that starts after current job ends
        int newind = getnextindex(p, i + 1, now.second.first);
        if (newind != -1)
            take += profit(p, newind);  // Add profit from next non-overlapping job

        int nottake = profit(p, i + 1);  // Profit if we skip the current job

        // Memoize and return the maximum of taking or skipping the current job
        return dp[i] = max(take, nottake);
    }

    // Main function to schedule jobs for maximum profit
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profits) {
        vector<pair<int, pair<int, int>>> p;  // Each job as {startTime, {endTime, profit}}

        memset(dp, -1, sizeof(dp));  // Initialize DP array

        // Create job list with start time, end time, and profit
        for (int i = 0; i < startTime.size(); i++) {
            p.push_back({startTime[i], {endTime[i], profits[i]}});
        }

        sort(p.begin(), p.end());  // Sort jobs by start time

        return profit(p, 0);  // Start recursion from index 0
    }
};
