class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> storage;
        vector<vector<string>> answer;

        for (const string s : strs) {
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += "|" + to_string(count[i]);
            }
            storage[key].push_back(s);
        }

        for (auto groups: storage) {
            answer.push_back(groups.second);
        }

        return answer;
    }
};
