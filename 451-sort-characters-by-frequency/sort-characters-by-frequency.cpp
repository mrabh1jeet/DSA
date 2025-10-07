class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto c:s){
            freq[c]++;
        }
        vector<pair<char,int>>chars(freq.begin(),freq.end());
        sort(chars.begin(),chars.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        string result;
        for(auto &[ch,count]:chars){
            result.append(count,ch);
        }
        return result;
    }
};