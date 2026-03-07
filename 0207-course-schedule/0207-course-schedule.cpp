class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();q.pop();
            ans.push_back(curr);
            for(auto neigh : adj[curr]){
                inDegree[neigh]--;
                if(inDegree[neigh]==0) {q.push(neigh);}
            }
        }
        if(ans.size()==numCourses) return true;
        return false;
    }
};