class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;

        while (i >= 0) {
            // 1. Skip trailing/intermediate spaces
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            // 2. Find the end of the word
            int j = i;
            while (i >= 0 && s[i] != ' ') i--;

            // 3. Extract the word and add to answer
            if (ans.empty()) {
                ans = s.substr(i + 1, j - i);
            } else {
                ans += " " + s.substr(i + 1, j - i);
            }
        }
        return ans;
    }
};