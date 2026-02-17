class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
         vector<string> ans;
    // Iterate through every possible hour (0-11) and minute (0-59)
    for (int h = 0; h <12; h++) {
        for (int m = 0; m < 60; m++) {
            // __builtin_popcount counts the number of set bits (1s)
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                string time = to_string(h) + (m < 10 ? ":0" : ":") + to_string(m);
                ans.push_back(time);
            }
        }
    }
    return ans;
    }
};