class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int n : nums) {
            numSet.insert(n);
        }

        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int curnum = num + 1;
                int curlen = 1;
                while (numSet.find(curnum) != numSet.end()) {
                    curnum++;
                    curlen++;
                }
                longest = max(longest, curlen);
            }
        }

        return longest;
    }
};
