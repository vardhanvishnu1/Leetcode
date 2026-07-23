class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        long long n = nums.size();
        if(n<3) return n;
        vector<long long>p;
        p.push_back(2);
        while(1){
            long long x = p.back();
            p.push_back(2*x);
            if(x>2*n) break;
        }
        for(int i=0;i<p.size()-1;i++){
            if(n>=p[i]&&n<p[i+1]) return p[i+1];
        }
        return 0;
    }
};