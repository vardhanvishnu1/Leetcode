class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>v(nums2.size());
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()&&nums2[i]>s.top()){
                s.pop();
            }
            if(s.empty()){
                v[i]=-1;
            }
            else{
                v[i]=s.top();
            }
            s.push(nums2[i]);
        }
         unordered_map<int,int> st;
        for(int i=0;i<nums2.size();i++){
            st[nums2[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(v[st[nums1[i]]]);
        }
        return ans;
    }
};