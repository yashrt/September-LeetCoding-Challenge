class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int R = nums[0];
        
        int maxVal = R, minVal = R;
        for (int i = 1; i < n; i++) { 
   
            if (nums[i] < 0) std::swap(maxVal, minVal);
  
            maxVal = std::max(nums[i], maxVal * nums[i]); 
            minVal = std::min(nums[i], minVal * nums[i]); 
            R = max(R, maxVal); 
        } 
        return R;
    }
};
