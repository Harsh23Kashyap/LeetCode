class Solution {
public:
    class Trie{
        public:
        unordered_map<char,Trie*> children;
        vector<string> words;
        bool possible;
        char ch;
        Trie(char ch, bool possible){
            this->ch=ch;
            this->possible=possible;
        }
    };
    Trie *root = new Trie('/', false);
    void insertAt(string word){

        Trie *curr=root;
        for(int i=0;i<word.size();i++){
           if(curr->children.find(word[i]) == curr->children.end())
                curr->children[word[i]]=new Trie(word[i],false);
          curr = curr->children[word[i]];
          curr->words.push_back(word);
        }
        curr->possible=true;
    }
   

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         vector<vector<string>> ans;
        sort(products.begin(), products.end());

         for(auto it:products)
            insertAt(it);

        

        Trie* curr=root;
        bool prefix=true;
         for(int i=0;i<searchWord.size();i++)
         {
            vector<string> currans;
            char ch=searchWord[i];
            if(!prefix or !curr->children.count(ch)){
                prefix=false;
                ans.push_back(currans);
                continue;

            }

            curr=curr->children[(ch)];
            vector<string> all=curr->words;
            sort(all.begin(),all.end());
            if(all.size()>3){
                currans.insert(currans.end(),all.begin(), all.begin()+3);
                ans.push_back(currans);
            }
            else
                ans.push_back(all);


         }
         return ans;
    }
};