class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        map<char,int>freq;
        for(int i=0;i<n;i++){
            freq[t[i]]++;
        }
        map<char,int>mp;
        int l = 0;
        int r = 0;
        vector<pair<int,int>>ans;
        int cnt = 0;
        while(r<m){
            mp[s[r]]++;
            if(freq.count(s[r])&&mp[s[r]]==freq[s[r]]) cnt++;
            while(cnt>=freq.size()){
                if(cnt==freq.size()) {ans.push_back({l,r});}
                mp[s[l]]--;
                if(freq.count(s[l])&&mp[s[l]]<freq[s[l]]){
                    cnt--;
                }
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
    long long idx = -1 ;
    int len = INT_MAX;
    for(int i=0;i<ans.size();i++){
        if(ans[i].second-ans[i].first+1<len){
            len = ans[i].second-ans[i].first+1;
            idx = i;
        }
    }
    if(idx==-1) return "";
    return s.substr(ans[idx].first,len);
    }
};