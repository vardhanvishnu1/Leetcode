class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
        if(ans.size()!=numCourses) return {};
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};