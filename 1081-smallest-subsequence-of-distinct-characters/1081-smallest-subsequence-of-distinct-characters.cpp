class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,int>pos;
        for(int i=0;i<s.size();i++){
            pos[s[i]]=i;
        }
        string ans;
        vector<bool>visited(26,false);
        for(int i=0;i<s.size();i++){
            if(visited[s[i]-'a']) continue;
            if(ans.empty()) {ans.push_back(s[i]);visited[s[i]-'a']=true;}
            else{
                while(!ans.empty()&&ans.back()>s[i]&&pos[ans.back()]>i){
                    visited[ans.back()-'a'] = false;
                    ans.pop_back();
                }
                visited[s[i]-'a']=true;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};