class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        unordered_map<string, vector<string>> mp;
        
        for (string &p : products) {
            string prefix = "";
            for (char c : p) {
                prefix += c;
                mp[prefix].push_back(p);
            }
        }
        
        for (auto &it : mp) 
            sort(it.second.begin(), it.second.end());
        
        vector<vector<string>> result;
        string prefix = "";
        
        // Answer queries
        for (char c : searchWord) {
            prefix += c;
            
            vector<string> temp;
            
            if (mp.count(prefix)) {
                for (int i = 0; i < min(3, (int)mp[prefix].size()); i++) {
                    temp.push_back(mp[prefix][i]);
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};
