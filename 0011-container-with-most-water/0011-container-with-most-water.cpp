class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int l = 0;
        int r = heights.size() - 1;
        if (r == 0) {
            return 0;
        }

        while (l < r) {
            int curmax = (r - l) * min(heights[l], heights[r]);
            max = (curmax <= max) ? max : curmax;
            if (heights[l] >= heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return max;
    }
};
