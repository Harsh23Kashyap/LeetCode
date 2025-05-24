class Solution {
public:
    bool there(string w, char a){
        for(auto it:w){
            if(it==a)
            return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            if(there(words[i],x))
            ans.push_back(i);
        }
        return ans;
    }
};