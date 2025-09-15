class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] >= b[0];
        });


        vector<vector<int>> answer;
        if (intervals.empty()) {
            return answer;
        }

        vector<int> temp = intervals.back();
        intervals.pop_back();
        answer.push_back(temp);

        while (!intervals.empty()) {
            vector<int> temp = intervals.back();
            intervals.pop_back();

            if (temp[0] <= answer.back()[1]) {
                if (temp[1] > answer.back()[1]) {
                    answer.back()[1] = temp[1];
                }
            } else {
                answer.push_back(temp);
            }
        }

        return answer;
    }
        
};