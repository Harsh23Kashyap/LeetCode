class Solution {
public:
    struct Node {
        int child[26];
        int bestIdx;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.emplace_back(); // root
    }

    void updateBest(int node, int idx,
                    vector<string>& wordsContainer) {

        if (trie[node].bestIdx == -1) {
            trie[node].bestIdx = idx;
            return;
        }

        int currLen = wordsContainer[idx].size();
        int bestLen = wordsContainer[trie[node].bestIdx].size();

        if (currLen < bestLen ||
            (currLen == bestLen && idx < trie[node].bestIdx)) {
            trie[node].bestIdx = idx;
        }
    }

    void insert(string& word, int idx,
                vector<string>& wordsContainer) {

        int node = 0;

        updateBest(node, idx, wordsContainer);

        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[c];
            updateBest(node, idx, wordsContainer);
        }
    }

    int search(string& word) {
        int node = 0;

        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int totalChars = 1;
        for (auto& s : wordsContainer)
            totalChars += s.size();

        trie.reserve(totalChars);

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (auto& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};