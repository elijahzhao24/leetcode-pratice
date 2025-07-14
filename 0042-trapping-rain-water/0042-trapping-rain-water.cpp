class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftmax(height.size());
        vector<int> rightmax(height.size());

        int temp = 0;
        for (int i = 0; i < height.size(); i++) {
            leftmax[i] = temp;
            temp = max(height[i], temp);
        }
        temp = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            rightmax[i] = temp;
            temp = max(height[i], temp);
        }

        int total = 0;

        for (int i = 0; i < height.size(); i++) {
            total += (min(rightmax[i], leftmax[i]) - height[i] >= 0) ? (min(rightmax[i], leftmax[i]) - height[i]) : 0;
        }

        return total;
    }
};
