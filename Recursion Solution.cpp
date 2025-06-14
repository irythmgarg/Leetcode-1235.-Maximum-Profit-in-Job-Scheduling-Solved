class Solution {
public:

    // Recursive function to calculate maximum profit from job scheduling
    int profit(vector<pair<int, pair<int, int>>>& jobs, int i, int prevEnd) {
        // Base case: If all jobs have been considered
        if (i >= jobs.size())
            return 0;

        auto currentJob = jobs[i];
        int take = 0;

        // If current job's start time is after or at the end time of the previous job,
        // we can include this job
        if (prevEnd <= currentJob.first) {
            take = currentJob.second.second + profit(jobs, i + 1, currentJob.second.first);
        }

        // Option to not take the current job
        int notTake = profit(jobs, i + 1, prevEnd);

        // Return the maximum of taking or not taking the current job
        return max(take, notTake);
    }

    // Main function that prepares the job list and calls the recursive function
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profits) {
        vector<pair<int, pair<int, int>>> jobs;

        // Combine all job data into one vector of format: {start, {end, profit}}
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back({startTime[i], {endTime[i], profits[i]}});
        }

        // Sort jobs based on start time to consider jobs in a chronological manner
        sort(jobs.begin(), jobs.end());

        // Start recursive profit calculation from the first job with initial prevEnd = 0
        return profit(jobs, 0, 0);
    }
};
