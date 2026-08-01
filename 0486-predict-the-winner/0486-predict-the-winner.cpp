class Solution {
public:
    int solve(int turn,vector<int>&nums,int i,int j,int n){
        if(i>j) return 0;
        if(turn&1){
            return max(nums[i]+solve(turn+1,nums,i+1,j,n),nums[j]+solve(turn+1,nums,i,j-1,n));
        }
        else{
            return min(solve(turn+1,nums,i+1,j,n),solve(turn+1,nums,i,j-1,n)); 
        }

    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int total = accumulate(nums.begin(),nums.end(),0);
        int p1 = solve(1,nums,0,n-1,n);
        if(p1>=total-p1) return true;
        return false;
    }
};