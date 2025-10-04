class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> ma;
        unordered_map <char,int> mb;
        for(auto &el:s){
            ma[el]++;
        }
        for(auto &el:t){
            mb[el]++;
        }
        return ma==mb;
    }
};