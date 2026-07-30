class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int x = n/8;// 1
        int y = n%8;// 2
        int cnt = 0;
        cnt+=(1+x);
        return 4*(x*(x+1))+y*cnt;
    }
};