class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string l = to_string(low);string r = to_string(high);
        string ans = "123456789";
        int n = ans.size();
        vector<int>res;
        int mn_sz = l.size();
        int mx_sz = r.size();
        for(int i=mn_sz;i<=mx_sz;i++){
           for(int j=0;j+i<=n;j++){
                int x = stoi(ans.substr(j,i));
                if(x>=low&&x<=high) res.push_back(x);
            }
        }
        return res;
    }
};