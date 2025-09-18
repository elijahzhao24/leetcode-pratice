class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> storage;

        for (string s:strs) {

            vector<int> temp(26);  

            for (char c: s) {
                temp[c - 'a']++;
            }

            //convert to hashable string

            string tempstring;
            for (int i:temp) {
                tempstring.push_back('#');
                tempstring += to_string(i);
            }

            if (storage.count(tempstring)) {
                storage[tempstring].push_back(s);
            } else {
                storage[tempstring] = vector<string>{s};
            }
        }

        vector<vector<string>> answer;

        for (auto thing : storage) {
            answer.push_back(thing.second);
        }

        return answer;
    }
};