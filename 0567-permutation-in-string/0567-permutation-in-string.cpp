class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> s1map;
        unordered_map<char, int> s2map;
        int matches = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        int l = 0, r = 0;

        for (r; r<n1; r++) {
            s1map[s1[r]]++;
            s2map[s2[r]]++; 
        }

        for (auto it = s1map.begin(); it != s1map.end(); ++it) {
            if (it->second == s2map[it->first]) {
                matches++;
            }
        }

        int need = (int)s1map.size();

        if (matches == need) {
            return true;
        }

        while (r < n2) {

            char outc = s2[l];
            char inc = s2[r];

            if (s1map.count(outc)) {
                if (s1map[outc] == s2map[outc]) {
                    matches--;
                }
                s2map[outc]--;
                if (s1map[outc] == s2map[outc]) {
                    matches++;
                }
            } else {
                s2map[outc]--;
            }

            if (s1map.count(inc)) {
                if (s1map[inc] == s2map[inc]) {
                    matches--;
                }
                s2map[inc]++;
                if (s1map[inc] == s2map[inc]) {
                    matches++;
                }
            } else {
                s2map[inc]++;
            }

            r++;
            l++;
           
            if (matches == need) {
                return true;
            }
        }

        return false;
    }
};
