class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> rc(recipes.begin(), recipes.end());
        unordered_map<string, int> in;  // Stores the in-degree (dependencies count)
        queue<string> q;   
        unordered_map<string, vector<string>> edges; 

        // Build graph and in-degree map
        for(int i = 0; i < recipes.size(); i++) {
            for(auto &j : ingredients[i]) {
                edges[j].push_back(recipes[i]); 
                in[recipes[i]]++; 
            }
        }

        // Initialize queue with available supplies
        for(auto &supply : supplies) {
            q.push(supply);
        }
        
        // Process recipes using topological sorting (BFS)
        while(!q.empty()) {
            string item = q.front();
            q.pop();

            if(rc.count(item)) { // If it's a recipe, add to answer
                ans.push_back(item);
            }

            for(auto &recipe : edges[item]) { // Reduce in-degree of dependent recipes
                in[recipe]--;
                if(in[recipe] == 0) {
                    q.push(recipe); // If all ingredients are available, add to queue
                }
            }
        }
        return ans;
    }
};
