class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq; // max-heap
        int fuel = startFuel, prev = 0, stops = 0, i = 0;
        int n = stations.size();

        while (fuel < target) {
            // Add all reachable stations
            while (i < n && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) return -1; // can't move further

            fuel += pq.top(); // refuel with max fuel
            pq.pop();
            stops++;
        }
        return stops;
    }
};
