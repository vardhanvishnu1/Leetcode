class Solution {
public:
    string generate(int sz,int mx_sz,string curr,set<string>&s){
        if(sz>mx_sz) return "";
        if(sz==mx_sz){
            if(s.find(curr)==s.end()) return curr;
            return "";
        }
        string x = generate(sz+1,mx_sz,curr+"0",s);
        if(x!="") return x;
        string y = generate(sz+1,mx_sz,curr+"1",s);
        if(y!="") return y;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>s;
        int mx_sz = nums[0].size();
        for(auto el :nums){
            s.insert(el);
        }
        return generate(0,mx_sz,"",s);
    }
};