class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.size()==0 && str.size()==0)
            return false;
        
        unordered_map<char, vector<int>> lettersPos;
        unordered_map<string, vector<int>> wordsPos;
        
        vector<string> words;
        string temp="";
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]==' ')
            {
                words.push_back(temp);  
                temp = "";
            }
            else if(i==str.size()-1)
                words.push_back(temp+str[i]);
            else
                temp += str[i];
        }
        if(words.size() != pattern.size())
            return false;
        
        for(int i=0; i<pattern.size(); i++)
            lettersPos[pattern[i]].push_back(i);
        
        for(int i=0; i<words.size(); i++)
            wordsPos[words[i]].push_back(i);
        
        for (auto i=lettersPos.begin(); i!=lettersPos.end(); i++) 
        {
            bool temp = false;
            for (auto j=wordsPos.begin(); j!=wordsPos.end(); j++) 
            {
                if(i->second == j->second)
                {
                    temp = true;
                    break;
                }
            }
            if(!temp)
                return false;
        }
        
        return true;
    }
};
