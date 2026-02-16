class Solution {
public:
    void pass(queue<string>& q, string w, unordered_set<string> &vis, unordered_set<string>& words){

        for(int i=0;i<w.size();i++){
            char temp=w[i];
            for(char ch='a';ch<='z';ch++){
                w[i]=ch;
                if(words.find(w)!=words.end()){
                    if(vis.find(w)==vis.end()){
                        vis.insert(w);
                        q.push(w);
                    }
                }
            }
            w[i]=temp;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words(wordList.begin(),wordList.end());
        unordered_set<string> vis;
        int c=1;
        q.push(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                if(it==endWord)
                return c;
                pass(q,it,vis,words);
            }

        c++;
        }
        return 0;
    }
};