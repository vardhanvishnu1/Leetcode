class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<bool>visited(s1.size(),false);
        for(int i=0;i<s1.size();i++){
            // if(visited[i]) continue;
            bool found = false;
            for(int j =i;j<s1.size();j+=2){
                if(s1[i]==s2[j]){
                    // visited[i] = true;
                    // visited[j] = true;
                    swap(s1[j],s1[i]);
                    found = true;
                }
            }
            if(!found) return false;
        }
        return s1==s2;
    }
};