class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mn = INT_MAX;
        for(int i=1;i<n;i++){
            mn = min(mn,arr[i]-arr[i-1]);
        }
        vector<vector<int>>ans;
        int l=0;
        int r =1;
        while(r<n&&l<r){
            while(arr[r]-arr[l]>mn&&l<r) l++;
            if(l!=r) ans.push_back({arr[l],arr[r]});
            r++;
        }
        return ans;
    }
};