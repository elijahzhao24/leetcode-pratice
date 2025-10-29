class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int curNum = nums[i];
            curNum = abs(curNum);

            if (nums[curNum] <= 0) {
                return curNum;
            }
            nums[curNum] = -nums[curNum];
        }

        return 0;
    }
};
