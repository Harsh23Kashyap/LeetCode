class DSU {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb) {
            parent[pb] = pa;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;

        // Step 1: Initialize DSU + map email -> name
        for (auto& acc : accounts) 
        {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) 
            {
                string email = acc[i];
                if (!dsu.parent.count(email)) {
                    dsu.parent[email] = email;
                }
                emailToName[email] = name;
            }
        }
 
        for (auto& acc : accounts) {
            string firstEmail = acc[1];
            for (int i = 2; i < acc.size(); i++) {
                dsu.unite(firstEmail, acc[i]);
            }
        }
 
        unordered_map<string, vector<string>> groups;
        for (auto& [email, name] : emailToName) {
            string parent = dsu.find(email);
            groups[parent].push_back(email);
        }
 
        vector<vector<string>> res;
        for (auto& [parent, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(emailToName[parent]); // name
            for (auto& e : emails) temp.push_back(e);
            res.push_back(temp);
        }

        return res;
    }
};