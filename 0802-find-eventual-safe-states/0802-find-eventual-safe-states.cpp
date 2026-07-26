class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>in(n,0) ;  
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                in[i]++;
            adj[graph[i][j]].push_back(i);
            }
        }   
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<graph[i].size();j++){
        //       in[graph]
        //     }
        // }     
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neigh : adj[curr]){
                in[neigh]--;
                if(in[neigh]==0) q.push(neigh);
            }
        }
sort(ans.begin(),ans.end());
return ans;
    }
};