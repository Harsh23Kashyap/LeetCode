class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> rc(recipes.begin(), recipes.end());
        unordered_map<string, int> in;  
        queue<string> q;   
        unordered_map<string, vector<string>> edges; 

        for(int i = 0; i < recipes.size(); i++) {
            for(auto &j : ingredients[i]) {
                edges[j].push_back(recipes[i]); 
                in[recipes[i]]++; 
            }
        }

        for(auto &supply : supplies) {
            q.push(supply);
        }
        
        while(!q.empty()) {
            string item = q.front();
            q.pop();

            if(rc.count(item)) { 
                ans.push_back(item);
            }

            for(auto &recipe : edges[item]) { 
                in[recipe]--;
                if(in[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }
        return ans;
    }
};
