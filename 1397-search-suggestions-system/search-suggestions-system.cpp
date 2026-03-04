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
         for(int i=0;i<searchWord.size();i++){
            if(prefix and curr->children.find(searchWord[i]) != curr->children.end()){
            curr=curr->children[searchWord[i]];
             vector<string> temp=curr->words;
            sort(temp.begin(),temp.end());
            // cout<<temp.size()<<endl;
            if(temp.size()<=3)
                ans.push_back(temp);
            else
                ans.push_back({temp[0],temp[1],temp[2]});

            }
            else{
                prefix=false;
                ans.push_back({});
                continue;
            }
           
            // ans.push_back(curr->words);
         }
         return ans;
    }
};