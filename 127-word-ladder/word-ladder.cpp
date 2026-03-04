class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if(wordSet.find(endWord) == wordSet.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int level = 1;
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                
                string word = q.front();
                q.pop();
                
                if(word == endWord)
                    return level;
                
                for(int i=0;i<word.size();i++){
                    
                    char original = word[i];
                    
                    for(char c='a'; c<='z'; c++){
                        
                        word[i] = c;
                        
                        if(wordSet.find(word) != wordSet.end()){
                            
                            q.push(word);
                            wordSet.erase(word); // mark visited
                        }
                    }
                    
                    word[i] = original;
                }
            }
            
            level++;
        }
        
        return 0;
    }
};