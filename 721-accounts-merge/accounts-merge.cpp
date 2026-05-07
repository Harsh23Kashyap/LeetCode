class Solution {
public:

    unordered_map<string, string> parent;

    string find(string x) {

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(string x, string y) {

        string px = find(x);
        string py = find(y);

        if(px != py) {
            parent[py] = px;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, string> emailToName;

        // initialize DSU
        for(auto &acc : accounts) 
        {

            string name = acc[0];

            for(int i = 1; i < acc.size(); i++) {

                string email = acc[i];

                emailToName[email] = name;

                if(parent.find(email) == parent.end()) {
                    parent[email] = email;
                }
            }
        }

        // union emails in same account
        for(auto &acc : accounts) {

            string firstEmail = acc[1];

            for(int i = 2; i < acc.size(); i++) 
            {

                unite(firstEmail, acc[i]);
            }
        }

        // group emails by root parent
        unordered_map<string, vector<string>> groups;

        for(auto &[email, _] : emailToName) {

            string root = find(email);

            groups[root].push_back(email);
        }

        vector<vector<string>> ans;

        // build answer
        for(auto &[root, emails] : groups) {

            sort(emails.begin(), emails.end());

            vector<string> temp;

            // add name
            temp.push_back(emailToName[root]);

            // add emails
            for(auto &email : emails) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};