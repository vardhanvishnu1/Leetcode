class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string>s;
        for(int i=0;i<n;i++) s.insert(wordList[i]);
        if(!s.count(endWord)) return 0;
        queue<string>q;
        q.push(beginWord);
        int l = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string cur = q.front();
                q.pop();
                if(cur==endWord) return l;
                for(int i=0;i<cur.size();i++){
                    string temp = cur;
                    for(int j=0;j<26;j++){
                        temp[i] = 'a'+j;
                        if(s.count(temp)){ q.push(temp);s.erase(temp);}
                    }
                }
            }
            l++;
        }
        return 0;
    }
};