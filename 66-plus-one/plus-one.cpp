class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit and process carry
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;  // Just increment and return
                return digits;
            }
            digits[i] = 0;  // Reset to 0, carry continues
        }

        // If all digits were 9, we need a new leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
