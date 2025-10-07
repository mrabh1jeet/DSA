class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return ""; 
        int n=s.size();
        int start =0;
        int maxlen=1;
        auto expand=[&](int left,int right){
            while(left>=0 && right <n && s[left]==s[right]){
                left--;
                right++;
            }
            int len =right-left-1;
            if (len>maxlen){
                maxlen = len;
                start = left + 1;
            }
        };
            for(int i=0;i<n;i++){
                expand(i,i);
                expand(i,i+1); 
        } 
        return s.substr(start,maxlen);       
    }
};