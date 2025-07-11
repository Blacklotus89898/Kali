class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int len = startTime.size();
        vector<int> freeTimes;

        // First free time before first meeting
        freeTimes.push_back(startTime[0]);

        // Free time between meetings
        for (int i = 1; i < len; ++i) {
            freeTimes.push_back(startTime[i] - endTime[i - 1]);
        }

        // Free time after last meeting
        freeTimes.push_back(eventTime - endTime[len - 1]);

        // Sliding window of size k+1 (skipping up to k intervals means taking k+1 free periods)
        int windowSize = k + 1;
        int maxSum = 0, currSum = 0;

        // Initial window
        for (int i = 0; i < windowSize && i < freeTimes.size(); ++i) {
            currSum += freeTimes[i];
        }
        maxSum = currSum;

        // Slide the window
        for (int l = 0, r = windowSize; r < freeTimes.size(); ++l, ++r) {
            currSum = currSum - freeTimes[l] + freeTimes[r];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};