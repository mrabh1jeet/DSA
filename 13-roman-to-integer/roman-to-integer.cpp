#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            int val = values[s[i]];
            
            // If next symbol is bigger, subtract current value
            if (i + 1 < s.size() && val < values[s[i + 1]]) {
                total -= val;
            } else {
                total += val;
            }
        }
        return total;
    }
};
