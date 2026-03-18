class Solution {
public:
int lower(vector<int>& nums, int target){
    int n =nums.size();
        int  lo=0;
        int hi =n-1;
        int st = -1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                st = mid;hi=mid-1;
            }
            else if(nums[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
        return st;
}

int upper(vector<int>& nums, int target){
    int n =nums.size();
        int  lo=0;
        int hi =n-1;
        int end = -1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                end = mid;lo = mid+1;
            }
            else if(nums[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
        return end;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        int  lo=0;
        int hi =n-1;
        int st=-1,end=-1;
        st = lower(nums,target);end = upper(nums,target);
        return {st,end};
    }
};