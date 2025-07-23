class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int storage[26] = {0};
        for (char c : tasks) {
            storage[c - 'A']++;
        }

        priority_queue<int> pq;
        for (int i:storage) {
            if (i > 0) {
                pq.push(i);
            }
        }

        int steps = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            while (cycle > 0 && !pq.empty()) {
                int cnt = pq.top(); 
                pq.pop();
                if (cnt - 1 > 0)
                    temp.push_back(cnt - 1);
                steps++;
                cycle--;
            }

            for (int i :temp) {
                pq.push(i);
            }

            if (pq.empty()) {
                return steps;
            } else {
                steps += cycle;
            }

        }
        return steps;
    }
};