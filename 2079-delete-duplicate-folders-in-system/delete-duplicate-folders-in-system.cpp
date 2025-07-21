class TrieNode {
public:
    string name;
    unordered_map<string, TrieNode*> children;
    string hash;
    bool isDuplicate = false;

    TrieNode(string name = "") : name(name) {}
};

class Solution {
    unordered_map<string, int> hashCount;

    // Step 1: Build Trie
    void insert(TrieNode* root, vector<string>& path) {
        TrieNode* curr = root;
        for (string& folder : path) {
            if (!curr->children.count(folder)) {
                curr->children[folder] = new TrieNode(folder);
            }
            curr = curr->children[folder];
        }
    }

    // Step 2: Post-order DFS to create subtree signatures (hashes)
    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<string> subHashes;
        for (auto& [childName, childNode] : node->children) {
            string childHash = serialize(childNode);
            subHashes.push_back("(" + childName + childHash + ")");
        }

        sort(subHashes.begin(), subHashes.end());  // Ensure consistent order
        node->hash = accumulate(subHashes.begin(), subHashes.end(), string());

        hashCount[node->hash]++;
        return node->hash;
    }

    // Step 3: DFS again to mark duplicates
    void markDuplicates(TrieNode* node) {
        if (!node->hash.empty() && hashCount[node->hash] > 1) {
            node->isDuplicate = true;
            return; // Skip its children
        }

        for (auto& [_, child] : node->children) {
            markDuplicates(child);
        }
    }

    // Step 4: DFS to collect valid paths
    void collectPaths(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [childName, childNode] : node->children) {
            if (childNode->isDuplicate) continue;
            path.push_back(childName);
            result.push_back(path);
            collectPaths(childNode, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();

        // 1. Build Trie
        for (auto& path : paths) {
            insert(root, path);
        }

        // 2. Serialize subtrees
        serialize(root);

        // 3. Mark duplicates
        markDuplicates(root);

        // 4. Collect remaining paths
        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);
        return result;
    }
};
