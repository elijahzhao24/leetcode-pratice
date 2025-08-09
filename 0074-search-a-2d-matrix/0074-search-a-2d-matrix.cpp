class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target) {
                if (mid + 1 > matrix.size() - 1 || matrix[mid+1][0] > target) {
                    return insidesearch(matrix[mid], target);
                } else {
                    //greater than current 
                    low = mid + 1;
                }
            } else {
                high = mid - 1;        
            }
        }
        return false;
    }

    bool insidesearch(vector<int>& matrix, int target) {
        int high = matrix.size() -1;
        int low = 0;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (target == matrix[mid]) {
                return true;
            } else if (target > matrix[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
