class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int max_time = -1;
        
        sort(A.begin(), A.end());

        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1)
            return "";
        else
        {
            int hour = max_time / 60;
            int min = max_time % 60;
            
            string res = "";
            if(hour<10)
                res += "0";
            res += to_string(hour);
            
            res += ":";
            
            if(min<10)
                res += "0";
            res += to_string(min);
            
            return res;
        }
    }
};
