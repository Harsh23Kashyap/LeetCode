class Solution {
public:
    struct Trie {
        int bestIdx;
        int child[26];

        Trie() {
            bestIdx = -1;
            memset(child, -1, sizeof(child));
        }
    };

    vector<Trie> trie;
    vector<int> len;

    void updateNode(int node, int idx) {
        if (trie[node].bestIdx == -1 ||
            len[idx] < len[trie[node].bestIdx] ||
            (len[idx] == len[trie[node].bestIdx] &&
             idx < trie[node].bestIdx))
        {
            trie[node].bestIdx = idx;
        }
    }

    void insert(const string& s, int idx) {
        int node = 0;

        updateNode(node, idx);

        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[c];
            updateNode(node, idx);
        }
    }

    int search(const string& s) {
        int node = 0;

        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                return trie[node].bestIdx;
            }

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        len.resize(wordsContainer.size());

        long long totalChars = 1;
        for (int i = 0; i < wordsContainer.size(); i++) {
            len[i] = wordsContainer[i].size();
            totalChars += wordsContainer[i].size();
        }

        trie.reserve(totalChars + 1);
        trie.emplace_back(); // root

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (const string& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};