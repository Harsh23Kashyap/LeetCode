class Solution {
public:
    unordered_set<string> dict;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        for (auto &w : wordList) 
            dict.insert(w);

        vector<vector<string>> res;
        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;

            while (sz--) 
            {
                string word = q.front(); 
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) 
                {
                    char old = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;

                        if (dict.count(word) && !visited.count(word)) {
                            if (word == endWord) 
                                found = true;

                            if (!levelVisited.count(word))
                             {
                                q.push(word);
                                levelVisited.insert(word);
                            }

                            parent[word].push_back(original);
                        }
                    }
                    word[i] = old;
                }
            }

            for (auto &w : levelVisited)
                visited.insert(w);
        }

        if (!found) 
            return res;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, parent, path, res);

        return res;
    }

    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& res) {

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path, res);
            path.pop_back();
        }
    }
};