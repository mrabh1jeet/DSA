class Solution {
public:
    int mindays(vector<int>weight,int capacity ){
        int n=weight.size();
        int days=1,load=0;
        for(int i=0;i<n;i++){
            if(load+weight[i]>capacity){
                days=days+1;
                load=weight[i];
            }
            else{
                load+=weight[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int nofdays=mindays(weights,mid);
            if(nofdays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;       
    }
};