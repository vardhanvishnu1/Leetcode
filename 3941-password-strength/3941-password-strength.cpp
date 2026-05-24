class Solution {
public:
    int passwordStrength(string s) {
        int ans =0;
        map<char,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            if(freq[s[i]]<2){
                if(s[i]>='a'&&s[i]<='z') ans++;
                else if(s[i]>='A'&&s[i]<='Z') ans+=2;
                else if(isdigit(s[i])) ans+=3;
                else ans+=5;
            }
        }
        return ans;
    }
};