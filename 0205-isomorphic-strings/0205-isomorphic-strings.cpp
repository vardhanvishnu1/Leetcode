class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapStoT;
        unordered_map<char, char> mapTtoS;
        for (int i = 0; i < s.size(); i++) {
            char charS = s[i];
            char charT = t[i];
            if (mapStoT.count(charS)) {
                if (mapStoT[charS] != charT) return false;
            } 
            else {
                mapStoT[charS] = charT;
            }
            if (mapTtoS.count(charT)) {
                if (mapTtoS[charT] != charS) return false;
            } 
            else {
                mapTtoS[charT] = charS;
            }
        }
        return true;
    }
};