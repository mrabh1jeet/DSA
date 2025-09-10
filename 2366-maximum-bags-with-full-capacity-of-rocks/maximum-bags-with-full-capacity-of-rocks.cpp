class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> need(n);

        for (int i = 0; i < n; i++) {
            need[i] = capacity[i] - rocks[i];
        }

        sort(need.begin(), need.end());

        int fullBags = 0;
        for (int i = 0; i < n; i++) {
            if (need[i] == 0) {
                fullBags++; // already full
            } else if (additionalRocks >= need[i]) {
                additionalRocks -= need[i];
                fullBags++;
            } else {
                break;
            }
        }

        return fullBags;
    }
};
