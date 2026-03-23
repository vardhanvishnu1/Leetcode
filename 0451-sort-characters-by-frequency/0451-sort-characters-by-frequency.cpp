class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<vector<char>>f(n+1);
        for(auto el : mp){
            f[el.second].push_back(el.first);
        }
        string ans ="";
        for(int i=n;i>0;i--){
            for(int j=0;j<f[i].size();j++) ans.append(i,f[i][j]);
        }
        return ans;
    }
};