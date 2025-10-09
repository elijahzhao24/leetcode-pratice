class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) {
            return 0;
        }

        // must eat all bananas within h
        // each pile will take ceil(pile/k);
        // use binary search to find options
        // if does not finish pile, increase eating speed by moving l
        // if finish pile, record if it is the fastest seen time, move r to -1 of current

        // return mininmum k

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int returnVal = r;

        while (l <= r) {
            int m = l + (r-l)/2;
            int curHours = 0;
            for (int i : piles) {
                curHours += (static_cast<long long>(i) + m - 1) / m;
                if (curHours > h) {
                    break;
                }
            }

            if (curHours <= h) {
                returnVal = min(returnVal, m);
                r = m-1;
            } else {
                l = m + 1;
            }
        }

        return returnVal;
    }
};