class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> u;
        for(string a:strs)
        {
            string c=a;
            sort(c.begin(),c.end());
            u[c].push_back(a);
        }
        for(auto it: u)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};