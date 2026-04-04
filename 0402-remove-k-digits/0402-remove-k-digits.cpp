class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = ""; // Using string as a stack for efficiency
        for (char c : num) {
            // While the current digit is smaller than the last added digit, pop it
            while (!res.empty() && res.back() > c && k > 0) {
                res.pop_back();
                k--;
            }
            
            // Avoid leading zeros unless the result is empty
            if (!res.empty() || c != '0') {
                res.push_back(c);
            }
        }
        // If k > 0, remove digits from the end (the largest digits in our monotonic stack)
        while (!res.empty() && k > 0) {
            res.pop_back();
            k--;
        }
        return res.empty() ? "0" : res;
    }
};