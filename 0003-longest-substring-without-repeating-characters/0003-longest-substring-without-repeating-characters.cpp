class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int answer = 0;
        int bottomindex = 0;
        int siz = s.size();

        unordered_map<char, int> lastseen;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (lastseen.count(c)) {
                if (lastseen[c] >= bottomindex) {
                    answer = max(answer, i - bottomindex);
                    bottomindex = lastseen[c] + 1;
                    lastseen[c] = i;
                } else {
                    lastseen[c] = i;
                }
            } else {
                lastseen[c] = i;
            }
        }

        answer = max(answer, siz - bottomindex);
        return answer;
        
    }
};
