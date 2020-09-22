class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> timestamp;
        for(auto trip : trips)
        {
            timestamp[trip[1]]+=trip[0];
            timestamp[trip[2]]-=trip[0];
        }
        int cap = 0;
        for(auto number : timestamp)
        {
            cap += number.second;
            if(cap > capacity)
                return false;
        }
        return true;
    }
};
