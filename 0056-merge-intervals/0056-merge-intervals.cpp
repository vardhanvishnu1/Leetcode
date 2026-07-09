class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        int n = i.size();
        sort(i.begin(),i.end());
        vector<vector<int>>ans;
        for(auto el : i){
            if(ans.empty()||ans.back()[1]<el[0]) ans.push_back(el);
            else{
                ans.back()[1] = max(ans.back()[1],el[1]);
            }
        }
        return ans;
    }
};