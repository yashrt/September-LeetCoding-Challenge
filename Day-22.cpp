class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0)
            return res;
            
        int num1 = nums[0], num2 = nums[0]; 
        int count1 = 1, count2 = 0 ;
        
        for (int val : nums) 
        {
            if(val == num1)
                count1++;
            else if (val == num2)
                count2++;
            else if (count1 == 0) 
            {
                num1 = val;
                count1++;
            }
            else if (count2 == 0)
            {
                num2 = val;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int val : nums) {
            if(val == num1)
                count1++;
            else if(val == num2)
                count2++;
        }
        if(count1 > nums.size()/3)
            res.push_back(num1);
        if(count2 > nums.size()/3)
            res.push_back(num2);
        return res;
    }
};
