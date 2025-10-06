class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last_merged = merged_intervals.back();

            if (intervals[i][0] <= last_merged[1]) {
                last_merged[1] = max(last_merged[1], intervals[i][1]);
            } else {
                merged_intervals.push_back(intervals[i]);
            }
        }

        return merged_intervals;
    }
};