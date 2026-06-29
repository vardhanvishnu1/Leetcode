class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string>s;
        int n = word.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string x = word.substr(i,j-i+1);
                s.insert(x);
            }
        }
        int ans = 0;
        for(int i=0;i<patterns.size();i++){
            if(s.find(patterns[i])!=s.end()) ans++;
        }
        return ans;
    }
};