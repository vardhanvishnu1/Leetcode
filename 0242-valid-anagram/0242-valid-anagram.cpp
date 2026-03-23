class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1st approach 
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;
        // 2nd approach
        // if(s.size()!=t.size()) return false;
        // map<char,int>mp1;
        // map<char,int>mp2;
        // for(int i=0;i<s.size();i++){
        //     mp1[s[i]]++;
        // }
        // for(int i=0;i<t.size();i++){
        //     mp2[t[i]]++;
        // }
        // for(auto el : mp1){
        //     if(el.second!=mp2[el.first]) return false;
        // }
        // return true;
        //3rd approach
        if(s.size()!=t.size()) return false;
        int f[26];
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
            f[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(f[i]!=0) return false;
        }
        return true;
    }
};