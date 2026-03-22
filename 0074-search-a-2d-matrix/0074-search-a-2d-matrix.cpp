class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(!(matrix[i][0]<=target&&target<=matrix[i][m-1])) continue;
            int lo = 0;
            int hi = m-1;
            int mid;
            while(lo<=hi){
                mid = lo + (hi-lo)/2;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]>target) hi = mid-1;
                else lo = mid+1;
            }
        }
        return false;
    }
};