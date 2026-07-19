class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (((target[1]+target[0])%2))==(((start[0]+start[1])%2));
    }
};

//+1 +2 -1 -2

