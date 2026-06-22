class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string ans = "balloon";
        map<char,int>freq;
        map<char,int>rfreq;
        for(auto el : ans){
            rfreq[el]++;
        }
        for(auto el : text){
            if(!rfreq.count(el))  continue;
            freq[el]++;
        }
        int res = INT_MAX;
        for(auto el : rfreq){
            char ch = el.first;
            if(freq[ch]<rfreq[ch]) return 0;
            res = min(res,freq[ch]/rfreq[ch]);
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};