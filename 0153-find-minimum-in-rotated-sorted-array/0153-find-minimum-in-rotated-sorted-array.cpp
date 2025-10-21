class Solution {
public:
    int findMin(vector<int> &nums) {
        //get the middle, check if right pointer is less than it
        // if it is, min is within that range.

        int l = 0;
        int r = nums.size()-1;

        while (r>l) {
            int mid = l + (r-l)/2;

            if (nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};

