class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
        unordered_set<string> uu(wl.begin(),wl.end());


        unordered_set<string> vis;

        queue<string> q;

        q.push(beginWord);
        int curr=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                for(int i=0;i<it.size();i++){
                    char temp=it[i];
                    for(char ch='a';ch<='z';ch++){
                        it[i]=ch;
                        if(vis.find(it)==vis.end() and uu.find(it)!=uu.end()){
                            vis.insert(it);
                            q.push(it);

                            if(it==endWord)
                                return curr+1;

                        }
                    }
                    it[i]=temp;
                }
            }
            curr++;
        }
        return 0;
    }
};