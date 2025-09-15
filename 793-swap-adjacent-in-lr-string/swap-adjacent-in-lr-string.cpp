class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // skip X in both
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;

            if (i == n || j == n) return i == n && j == n;

            if (start[i] != end[j]) return false;

            if (start[i] == 'L' && i < j) return false; // L can't move right
            if (start[i] == 'R' && i > j) return false; // R can't move left

            i++;
            j++;
        }
        return true;
    }
};
