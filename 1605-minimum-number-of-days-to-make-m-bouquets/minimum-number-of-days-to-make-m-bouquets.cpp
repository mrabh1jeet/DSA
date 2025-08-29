class Solution {
public:
    bool possible(vector<int> &bloomDay ,int day,int m,int k ){
        int n = bloomDay.size();
        int count =0;
        int noOfBloom=0;
        for(int i =0;i<n;i++){
            if (bloomDay[i]<=day){
                count++;
            }
            else{
                noOfBloom+=(count/k);
                count=0;
            }
        }
        noOfBloom+=(count/k);
        return noOfBloom>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val=m*1LL*k*1LL;
        if(n<val)return -1;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i = 0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]); 
        }
        int low=mini,high=maxi;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (possible(bloomDay ,mid, m, k)){
                high=mid-1; 
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};