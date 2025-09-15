class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (complements.count(nums[i])) {
                vector<int> answer = {complements[nums[i]], i};
                return answer;
            }
            complements[target - nums[i]] = i;
        }
        return temp;
    }
};