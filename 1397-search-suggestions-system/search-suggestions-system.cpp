class Solution {
public:
    class Trie{
        public:
        unordered_map<char, Trie*> child;
        set<string> words;
        
    };
     void insert(Trie *t, string s){
        Trie *temp=t;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if (temp->child.find(ch) == temp->child.end()) {
                temp->child[ch] = new Trie();
            }
            temp=temp->child[ch];
             temp->words.insert(s);

        }
     }

    vector<vector<string>> suggestedProducts(vector<string>& products, string sw) {
    Trie *t = new Trie();
    for (const string& p : products) {
        insert(t, p);
    }

    vector<vector<string>> ans;
    Trie* curr = t;

    for (char ch : sw) {
        if (curr && curr->child.find(ch) != curr->child.end()) {
            curr = curr->child[ch];
            vector<string> temp;
            int k = 3;
            for (const auto& word : curr->words) {
                temp.push_back(word);
                if (--k == 0) break;
            }
            ans.push_back(temp);
        } else {
            while (ans.size() < sw.size()) {
                ans.push_back({});
            }
            break;
        }
    }

    return ans;
}

};