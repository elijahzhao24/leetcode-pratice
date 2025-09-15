class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0]; // ascending by start
             });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= ans.back()[1]) {
                // overlap → extend the end if needed
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // no overlap → add new interval
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
