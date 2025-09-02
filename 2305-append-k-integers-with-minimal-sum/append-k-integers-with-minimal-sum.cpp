class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        
        long long cur = 1;
        
        for (int x : nums) {
            if (x < cur) continue;  // skip duplicates and numbers < current
            if (x > cur) {
                long long cnt = min<long long>(k, x - cur);
                ans += (cur + cur + cnt - 1) * cnt / 2; // sum of arithmetic series
                k -= cnt;
            }
            cur = x + 1;
            if (k == 0) break;
        }
        
        // If still need more numbers after largest element in nums
        if (k > 0) {
            ans += (cur + cur + k - 1) * (long long)k / 2;
        }
        
        return ans;
    }
};
