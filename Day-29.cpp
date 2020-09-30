class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<n; i++)
        {
            if(!dp[i])
                continue;
            for(auto word: wordDict)
            {
                int len = word.size();
                if(i+len>n)
                    continue;
                if(word == s.substr(i, len))
                    dp[i+len] = true;
            }
        }
        return dp[n];
    }
};
