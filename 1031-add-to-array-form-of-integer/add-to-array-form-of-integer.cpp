class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i = num.size() - 1;

        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];  // add digit
                i--;
            }
            result.push_back(k % 10); // current digit
            k /= 10;                  // carry
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
