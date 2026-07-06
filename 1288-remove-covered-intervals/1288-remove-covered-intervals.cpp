class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
     [](vector<int>& a, vector<int>& b) {
         if (a[0] == b[0])
             return a[1] > b[1];   // larger end first
         return a[0] < b[0];
     });
        int n = intervals.size();
        int cnt =0;
        for(int i=0;i<n-1;i++){
            int c = intervals[i][0];
            int d = intervals[i][1];
            int a = intervals[i+1][0];
            int b = intervals[i+1][1];
            if(c<=a&&b<=d) {cnt++;}
            intervals[i+1][1] = max(b,d);
        }
        return n-cnt;
    }
};