class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l =0;
        int r =0;
        int ans = 0;
        map<int,int>freq;
        while(r<n){
            freq[fruits[r]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0) freq.erase(fruits[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
    return ans;
    }
};