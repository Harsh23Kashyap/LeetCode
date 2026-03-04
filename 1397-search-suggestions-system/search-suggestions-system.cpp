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

    for(auto &it : products)
        insertAt(it);

    Trie* curr = root;
    bool prefixExists = true;

    for(int i = 0; i < searchWord.size(); i++) {

        if(prefixExists && curr->children.count(searchWord[i])) {
            curr = curr->children[searchWord[i]];

            vector<string> temp = curr->words;
            if(temp.size() > 3)
                temp.resize(3);

            ans.push_back(temp);
        }
        else {
            prefixExists = false;
            ans.push_back({});
        }
    }

    return ans;
}
};