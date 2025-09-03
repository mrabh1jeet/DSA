class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Mark visited numbers as negative
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1; // convert value to index
            if (nums[index] > 0) {
                nums[index] = -nums[index]; 
            }
        }
        
        // Step 2: Collect numbers that were not marked
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) { // means i+1 was never visited
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};
