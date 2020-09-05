class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size()==0)
            return {};
        unordered_map<char,int> last;
        int maxLast = 0;
        int sum = 0;
        vector<int> res;
        
        for(int i=0; i<S.size(); i++)
            last[S[i]] = i;
        
        for(int i=0; i<S.size(); i++)
        {
            if(last[S[i]]==maxLast && i==maxLast)
            {
                res.push_back(i-sum+1);
                sum += res.back();
                maxLast = i+1;
            }
            else if(last[S[i]] > maxLast)
                maxLast = last[S[i]];
        }
        return res;
    }
};
