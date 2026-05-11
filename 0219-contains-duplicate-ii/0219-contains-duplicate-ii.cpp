class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int idx;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) { //if element exists in hash map
                idx = mp[nums[i]]; //store the previous index in 'idx'
                if (abs(idx - i) <= k) 
                    return true;
            }
            mp[nums[i]] = i; //add element to hash map when it does not exist
        }
        return false;
    }
};