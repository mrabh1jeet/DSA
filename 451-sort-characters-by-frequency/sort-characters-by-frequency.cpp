class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Sort characters by frequency using a vector of pairs
        vector<pair<char, int>> chars(freq.begin(), freq.end());
        sort(chars.begin(), chars.end(), [](auto &a, auto &b) {
            return a.second > b.second; // Sort descending by frequency
        });

        // Step 3: Build the result string
        string result;
        for (auto &[ch, count] : chars) {
            result.append(count, ch);
        }

        return result;
    }
};
