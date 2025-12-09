class Solution {
private:
    bool dfs(int node,int col,vector<int>&color,vector<vector<int>>& graph){
        color[node] = col;
        for(auto el : graph[node]){
            if(color[el]==-1){
                if(dfs(el,!col,color,graph)==false) return false;
            }
            else if(color[el]!=-1&&color[el]==col) return false;
        }
        return true;
    }
    public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
               if(dfs(i,0,color,graph) == false) return false;;
            }
        }
        return true;
    }
};