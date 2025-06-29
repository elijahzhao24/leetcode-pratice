class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = 0;
        int l = numbers.size() - 1;

        while (numbers[r] + numbers[l] != target) {
            if (numbers[r] + numbers[l] > target) {
                l--;
            } else if (numbers[r] + numbers[l] < target) {
                r++;
            }
        }

        vector<int> returnVector{++r, ++l};

        return returnVector;
    }
};
