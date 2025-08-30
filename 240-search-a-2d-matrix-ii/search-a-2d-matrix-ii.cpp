class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row=0,coloum=m-1;
        while(row<n && coloum>=0){
            if(matrix[row][coloum]==target){
                matrix.clear();
                return true;
            }
            else if (matrix[row][coloum]<target){
                row++;
            }
            else{
                coloum--;
            }
        }
        matrix.clear();
        return false;
        
    }
};