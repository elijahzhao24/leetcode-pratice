class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int answer = 0;
        std::stack<pair<int, int>> storage;

        for (int i = 0; i < n; i++) {
            int lastindex = i;
            while (!storage.empty() && storage.top().second > heights[i]) {
                int maxheight = storage.top().second;
                lastindex = storage.top().first;
                storage.pop();
                answer = max(answer, maxheight * (i -lastindex));
            }
            storage.push({lastindex, heights[i]});
        }

        while (!storage.empty()) {
            int maxheight = storage.top().second;
            int lastindex = storage.top().first;
            storage.pop();
            answer = max(answer, maxheight * (n -lastindex));
        }
        
        return answer;
    }
};