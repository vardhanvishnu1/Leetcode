class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans =0;
        vector<bool>cnt(27,0);
        vector<bool>cnt1(27,0);
        for(int i=0;i<word.size();i++){
            if(word[i]<='z'&&word[i]>='a') cnt[(int)(word[i]-'a')] = true;
            else if(word[i]<='Z'&&word[i]>='A') cnt1[(int)(word[i]-'A')]=true; 
        }
        for(int i=0;i<27;i++){
            if(cnt[i]&&cnt1[i]) ans++;
        }
        return ans;
    }
};