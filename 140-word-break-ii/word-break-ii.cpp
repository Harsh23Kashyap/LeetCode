class Solution {
public:

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
    };

    TrieNode* root = new TrieNode();
    unordered_map<int, vector<string>> memo;

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    vector<string> dfs(string& s, int start) {

        if (memo.find(start)!=memo.end())
            return memo[start];

        if (start == s.size())
            return {""};

        vector<string> result;
        TrieNode* node = root;

        for (int i = start; i < s.size(); i++) {

            if (!node->children.count(s[i]))
                break;

            node = node->children[s[i]];

            if (node->isEnd) {

                string word = s.substr(start, i - start + 1);

                vector<string> suffixes = dfs(s, i + 1);

                for (string &suffix : suffixes) {

                    if (suffix == "")
                        result.push_back(word);
                    else
                        result.push_back(word + " " + suffix);
                }
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        for (string word : wordDict)
            insert(word);

        return dfs(s, 0);
    }
};
