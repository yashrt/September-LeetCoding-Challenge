class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int i=log10(low)+1; i<=log10(high)+1; i++)
        {
            for(int j=1; j<=10-i; j++)
            {
                int num = j;
                while(log10(num)<i)
                {
                    if(num%10 != 9)
                        num = num*10 + (num%10+1);
                    else
                        num = num*10;
                }
                num = num/10;
                if(num<low)
                    continue;
                else if(num>=low && num<=high)
                    res.push_back(num);
                else if(num>high)
                    return res;
            }
        }
        return res;
    }
};
