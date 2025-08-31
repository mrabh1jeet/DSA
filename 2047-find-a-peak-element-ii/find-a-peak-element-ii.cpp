class Solution {
public:

    int peakelement(vector<vector<int>>& mat, int n, int col) {
        int maxelement = -1;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxelement) {
                maxelement = mat[i][col];
                index = i;
            }
        }
        return index; 
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();       
        int m = mat[0].size();    

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;    
            int maxrow = peakelement(mat, n, mid); 

            int left = (mid - 1 >= 0) ? mat[maxrow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxrow][mid + 1] : -1;


            if (mat[maxrow][mid] > left && mat[maxrow][mid] > right) {
                return {maxrow, mid};
            }

            else if (left > mat[maxrow][mid]) {
                high = mid - 1;
            }
          
            else {
                low = mid + 1;
            }
        }
        return {-1, -1}; 
    }
};
