class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            if (complements.count(nums[i])) {
                answer.push_back(complements[nums[i]]);
                answer.push_back(i);
                return answer;
            }
            complements[target - nums[i]] = i;
        }
        return answer;
    }
};