class Solution {
public:
int maxEleRow(vector<vector<int>>& mat,int j){
    int idx = 0;
    int maxValue = -1;
    for(int i=0;i<mat.size();i++){
        if(mat[i][j]>maxValue){
            idx = i;
            maxValue = mat[i][j];
        }
    }
    return idx;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int lo = 0;
        int hi = mat[0].size()-1;
        int mid ;
        while(lo<=hi){
            mid = lo +(hi-lo)/2;
            int idx = maxEleRow(mat,mid);
            int left = mid-1 >= 0 ? mat[idx][mid-1] : -1;
            int right = mid+1 < mat[0].size() ? mat[idx][mid+1] : -1;
            if(mat[idx][mid]>left && mat[idx][mid]>right) return {idx,mid};
            else if(mat[idx][mid]<left) hi = mid-1;
            else lo = mid+1;
        }
        return {-1,-1};
    }
};