class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        vector<int>ans(n);
        string res = "";
        for(int i=0;i<n;i++){
            int x = 0;
            for(int j=0;j<words[i].size();j++){
                x += (weights[(int)(words[i][j]-'a')]);
            }
            ans[i] = x%26;
        }
    for(int i=0;i<n;i++){
        int x;
        x = (int)('a')+26-ans[i]-1;
        res+=(char)x;
    }
    return res;
    }
};