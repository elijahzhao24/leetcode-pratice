class Solution {
public:
    int characterReplacement(string s, int k) {

        // "AAABABB"
        unordered_map<char, int> letters;
        int longest = 0;

        int l = 0;
        int maxFrequency = 0;

        for (int r=0; r < s.size(); r++) {
            letters[s[r]]++;
            maxFrequency = max(maxFrequency, letters[s[r]]);

            while ( (r-l + 1 - maxFrequency) > k) {
                letters[s[l]]--;
                l++;
            }

            longest = max(longest, (r-l + 1));
        }

        return longest;
    }
};
