class Solution {
public:
    bool isValid(vector<vector<int>> grid, int i, int j, int m, int n)
    {
        return (i>=0 && i<m && j>=0 && j<n && grid[i][j]!=-1);
    }
    
    void traverseAll(vector<vector<int>> grid, int m, int n, int i, int j, int emptyCount, int& ans)
    {
        if(grid[i][j]==2 && emptyCount == 0)
            ans++;
        else
        {            
            grid[i][j] = -1;
            emptyCount--;
            
            if(isValid(grid, i-1, j, m, n))
                traverseAll(grid, m, n, i-1, j, emptyCount, ans);
            if(isValid(grid, i+1, j, m, n))
                traverseAll(grid, m, n, i+1, j, emptyCount, ans);
            if(isValid(grid, i, j-1, m, n))
                traverseAll(grid, m, n, i, j-1, emptyCount, ans);
            if(isValid(grid, i, j+1, m, n))
                traverseAll(grid, m, n, i, j+1, emptyCount, ans);
            
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int startX, startY;
        int emptyCount = 1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                    emptyCount++;
                else if(grid[i][j]==1)
                {
                    startX = i;
                    startY = j;
                }
            }
        }
        
        traverseAll(grid, m, n, startX, startY, emptyCount, ans);
        return ans;
    }
};
