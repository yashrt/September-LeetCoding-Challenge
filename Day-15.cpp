class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastIndex;
        for(int i=s.size()-1; i>=0; i--)
            if(s[i]!=' ')
            {
                lastIndex = i;
                break;
            }
        
        string temp = "";
        for(int i=0; i<=lastIndex; i++)
        {
            if(s[i]==' ')
                temp = "";
            else
                temp += s[i];
        }
        return temp.size();
    }
};
