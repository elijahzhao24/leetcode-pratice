class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int greatest_left[prices.size()];
        greatest_left[prices.size()-1] = 0;
        int curmax = prices[prices.size()-1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            greatest_left[i] = curmax;
            curmax = max(curmax, prices[i]);
        }

        int return_max = 0;
        for (int i = 0; i < prices.size(); i++) {
            int temp_max = greatest_left[i] - prices[i];
            return_max = max(return_max, temp_max);
        }

        return return_max;
    }
};
