class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        stack<int>s;
        vector<int>v(nums2.size());
        for(int i=2*nums2.size()-1;i>=0;i--){
            int idx = i % nums2.size();
            while(!s.empty()&&nums2[idx]>=s.top()){
                s.pop();
            }
            if(s.empty()){
                v[idx]=-1;
            }
            else{
                v[idx]=s.top();
            }
            s.push(nums2[idx]);
        }
        return v;
    }
};