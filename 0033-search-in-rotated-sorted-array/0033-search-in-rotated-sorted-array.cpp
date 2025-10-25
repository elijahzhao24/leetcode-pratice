class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r-l)/2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[r] < nums[mid]) {
                if (nums[mid] > target && nums[l] <= target ) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if (nums[l] > nums[mid]) {
                    if (nums[r] >= target && nums[mid] < target) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                } else {
                    if (nums[mid] < target) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
            }
               
        }
        return -1;
        // [1,2]
        //  l  r          
        //  m     
    }
};
