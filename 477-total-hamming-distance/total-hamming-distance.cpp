class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        
        // Check each of the 32 bits
        for (int bit = 0; bit < 32; bit++) {
            int countOnes = 0;
            for (int num : nums) {
                if (num & (1 << bit)) {
                    countOnes++;
                }
            }
            int countZeros = n - countOnes;
            total += (long long)countOnes * countZeros;
        }
        
        return (int)total;
    }
};
