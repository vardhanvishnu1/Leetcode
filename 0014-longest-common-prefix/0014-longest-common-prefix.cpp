class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i1 =0;
        int i2 =0;
        int n1 = strs[0].size();
        int n2 = strs.back().size();
        int n = strs.size();
        int cnt =0;
        while(i1<n1&&i2<n2){
            if(strs[0][i1]==strs[n-1][i2]) cnt++;
            else break;
            i1++;i2++;
        }
        return strs[0].substr(0,cnt);
    }
};