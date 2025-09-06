class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; num++) {
            string s = to_string(num);
            int n = s.size();

            if (n % 2 != 0) continue; // must be even length

            int half = n / 2;
            int leftSum = 0, rightSum = 0;

            for (int i = 0; i < half; i++) leftSum += s[i] - '0';
            for (int i = half; i < n; i++) rightSum += s[i] - '0';

            if (leftSum == rightSum) count++;
        }

        return count;
    }
};
