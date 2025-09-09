class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        
        int sum = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;   // skip banned numbers
            if (sum + i > maxSum) break;  // stop if exceeding sum
            
            sum += i;
            count++;
        }
        
        return count;
    }
};
