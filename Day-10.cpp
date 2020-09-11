class Solution {
public:
    string getHint(string secret, string guess) {
        string newSecret = "";
        string newGuess = "";
        int bull = 0;
        int cow = 0;
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i])
                bull++;
            else{
                newSecret += secret[i];
                newGuess += guess[i];
            }
        }
        
        unordered_map<char, int> umap;
        for(char ch: newSecret)
            umap[ch]++;
        for(int i=0; i<newGuess.size(); i++)
        {
            if(umap[newGuess[i]]>0)
            {
                umap[newGuess[i]]--;
                cow++;
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
