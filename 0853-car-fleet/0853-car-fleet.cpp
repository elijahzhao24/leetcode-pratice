class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create a hashmap to map the position to the index on speed array

        unordered_map<int, int> pos_to_index;

        for (int i = 0; i < position.size(); i++) {
            pos_to_index[position[i]] = i;
        }


        // sort position array from largest to smallest

        sort(position.begin(), position.end());


        // pop the top and find the amount of steps it takes to reach target
        // which is gonna be (target-position) + speed - 1/speed   (round up on int div)

        int total = 0;
        double last_time = 0;

        // if the next popped car has the same or more steps, don't increase the amount of fleets
        // if the next car has less steps, increase fleets++, and change global tracker for steps to current

        while(!position.empty()) {


            int curposition = position.back();
            int curspeed = speed[pos_to_index[curposition]];


            double time = double(target - curposition) / curspeed;

            cout << time << endl;

            if (last_time < time) {
                total++;
                last_time = time;
            }

            position.pop_back();

        }

        return total;

    }
};
