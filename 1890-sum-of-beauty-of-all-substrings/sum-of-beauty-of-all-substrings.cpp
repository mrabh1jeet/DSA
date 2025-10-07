class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;

        // Loop over all possible starting indices
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // Frequency of letters 'a' to 'z'

            // Expand substring from index i
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;  // Increment frequency of current character

                int maxFreq = 0;
                int minFreq = n+1;  // Large number to find minimum

                // Find max and min frequency for current substring
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {  // Only consider characters present in substring
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);  // Add beauty to total
            }
        }

        return totalBeauty;
    }
};
