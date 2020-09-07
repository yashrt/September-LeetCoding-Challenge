class Solution {
public:
    int maxOverlaping(vector<vector<int>> A, vector<vector<int>> B)
    {
        int max = 0;
        for(int row1=0; row1<A.size(); row1++)
        {
            for(int col1=0; col1<A[0].size(); col1++)
            {
                int temp = 0;
                for(int row2=0; row2+row1<A.size(); row2++)
                {
                    for(int col2=0; col2+col1<A.size(); col2++)
                    {
                       if(A[row2][col2]+B[row1+row2][col1+col2]==2)
                           temp++;
                    }
                }
                if(max<temp)
                    max=temp;
            }
        }
        return max;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int max1 = maxOverlaping(A, B);
        int max2 = maxOverlaping(B,A);
        return max(max1, max2);
    }
};
