class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>s;
        for(int i=0;i<n;i++) s.push_back(to_string(nums[i]));
        sort(s.begin(),s.end(),[](string a,string b) {return a+b>b+a;});
        if(s[0]=="0") return "0";
        string ans = "";
        for(int i=0;i<n;i++) ans+=s[i];
        return ans;
    }
};