class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int>diff(103,0);
        for(int i=0;i<n;i++){
            diff[logs[i][0]-1950]+=1;
            diff[logs[i][1]-1950]-=1;
        }   
        for(int i=1;i<103;i++){
            diff[i]+=diff[i-1];
        }
        int ans = 0;
        for(int i=1;i<103;i++){
            if(diff[i]>diff[ans]) ans = i;
        }
        return ans+1950;
    }
};