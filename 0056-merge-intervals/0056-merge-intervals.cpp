class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        if (intervals.empty()) {
            return ans;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

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