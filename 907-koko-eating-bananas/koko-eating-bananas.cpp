class Solution {
public:
        int findmax(vector <int> &v){
            return *max_element(v.begin(),v.end());
        }
        long long totalhrs(vector<int> &v,int hourly){
            int n=v.size();
            long long totalh=0;
            for (int i=0;i<n;i++){
                totalh+=((v[i]+hourly-1)/hourly);
            }
            return totalh;
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=findmax(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalh=totalhrs(piles,mid);
            if(totalh<=h){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }  
        return low;   
    }
};