class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int cnt = 1;
        int idx = v[0].second;
        arr[idx] = 1;
        int i = 1;
        while(i<n){
            while(i<n&&v[i-1].first==v[i].first){
                arr[v[i].second] = cnt;
                i++;
            }
            cnt++;
            if(i<n) arr[v[i].second] = cnt;
            i++;
        }
        return arr;
    }
};