class Solution {
public:
    static bool comp(int a, int b)
    {
        string strA = to_string(a);
        string strB = to_string(b);
        return  (strA+strB)>(strB+strA);
    }
    
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), comp);
        for(int num: nums)
            res += to_string(num);
        
        return (res[0]!='0') ? res : "0";
    }
};
