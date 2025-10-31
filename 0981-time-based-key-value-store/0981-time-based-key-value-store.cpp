class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!storage.count(key) || storage[key].empty()) {
            return "";
        }

        vector<pair<int, string>> & tempArray = storage[key];
        int l = 0, r = tempArray.size()-1;

        string result = "";
        while (r >= l) {
            int m = l + (r-l)/2;
            if (tempArray[m].first <= timestamp) {
                result = tempArray[m].second;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return result;
        
    }

private:
    // every key will point a array. The array will be sorted on timestamp
    unordered_map<string, vector<pair<int, string>>> storage;
};
