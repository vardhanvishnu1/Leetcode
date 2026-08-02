class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        if (n == 0) return 0; // Added safety for empty input
        
        //sort(planks.begin(),planks.end());
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[planks[i]]++;
        }
        
        //for(int i=0;i<n;i++) cout<<planks[i]<<" ";
        vector<pair<int,int>>p;
        for(auto el : mp){
            p.push_back({el.first,el.second});
        }
        sort(p.begin(),p.end());
        int m = p.size();
        
        map<int,int>freq;
        map<int,int>used;
        
        int ans = 0; // Changed from 1 to 0 to handle cases where max answer is actually 0
        for(auto el : mp){
            ans = max(ans,el.second);
        }
        
        for(int i=0;i<m;i++){
            // FIX 1: Change j = i + 1 to j = i to allow self-pairing
            for(int j=i;j<m;j++){ 
                int add = p[i].first+p[j].first;
                int c1 = p[i].second;
                int c2 = p[j].second;
                int c3 = 0;
                
                if(mp.count(add)) {
                        if(!used[add]) {
                            c3+=mp[add];
                            used[add]=1;
                        }
                }
                
                // FIX 2: Correctly calculate pairs depending on if elements are the same or distinct
                if (i == j) {
                    freq[add] += (c1 / 2) + c3; 
                } else {
                    freq[add] += min(c1,c2) + c3;
                }
            }
        }
        
        for(auto el : freq){
            ans = max(ans,el.second);
        }
        
        return ans;
    }
};