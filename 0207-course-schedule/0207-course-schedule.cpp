class Solution {
public:



    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>in(V,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            in[edges[i][1]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neigh : adj[curr]){
                in[neigh]--;
                if(in[neigh]==0) q.push(neigh);
            }
        }
    return (ans.size()==V);
    }
};




