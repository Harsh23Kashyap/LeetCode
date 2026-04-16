class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, set<int>> u;

        // Build map
        for(int i = 0; i < nums.size(); i++) {
            u[nums[i]].insert(i);
         }
 

        vector<int> ans;
 

        for(auto it : queries){ 

            int val = nums[it];

            auto &ss = u[val];  

 

            if(ss.size() == 1) { 
                ans.push_back(-1);
            }
            else {
                auto nex = ss.upper_bound(it);  
                int nval = INT_MAX, pval = INT_MAX;
                
                auto prev = ss.lower_bound(it);
                if(nex != ss.end()) {
                    nval = *nex - it; 
                    int tot=nums.size()-*nex + it; 
                    nval=min(nval,tot);
                }  
                else{ 
                   nval= nums.size()-it +*ss.begin();
                }

                if(prev != ss.begin()) {
                    --prev;
                    pval = it - *prev;  
                    int tot=*prev + nums.size()-it;  
                    pval=min(pval,tot);
                } 
                else{
                   pval =  it +(nums.size() - *ss.rbegin());
                }
                int res = min(pval, nval); 

                ans.push_back(res);
            }
        }
 

        return ans;
    }
};