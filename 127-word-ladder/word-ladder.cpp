class Solution {
public:
unordered_set<string> words;

    unordered_set<string> u;
    void pass(string s, queue<string> &q){
        
        for(int i=0;i<s.size();i++){
            char prev=s[i];
            for(char ch='a';ch<='z';ch++){
                s[i]=ch;
                if(words.find(s)!=words.end() and u.find(s)==u.end())
                    q.push(s);
            }
            s[i]=prev;

        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // (wordList.begin(),wordList.end());
        for(auto it:wordList)
            words.insert(it);
        queue<string> q;
        int c=1;
        // bool found-=true;
        q.push(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                cout<<it<<endl;
                if(it==endWord)
                return c;
                q.pop();
                if(u.find(it)!=u.end())
                    continue;
                u.insert(it);
                pass(it,q);

            }
            c++;
        }
        return 0;

    }
};