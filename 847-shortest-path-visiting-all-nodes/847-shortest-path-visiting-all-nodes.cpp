
class Solution {
public:
    int end_mask;
    int dp[13][10000]; 
    
    int solve(int u ,int mask, vector<vector<int>>& graph){

        if(dp[u][mask] != 0){
           return dp[u][mask];
        }
       
        if ((mask&(mask-1)) == 0) {
            return 0;
        }
        
       dp[u][mask]=INT_MAX -1;
       for(int v : graph[u]){
            if((mask&(1<<v))!= 0 ){
                int already_visited = solve(v, mask, graph);
                int not_visited = solve(v, mask ^ (1 << u), graph);
                int better_option =  1 + min(already_visited, not_visited);
                dp[u][mask] = min(dp[u][mask], better_option);
            }
        }
        
        return dp[u][mask];
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        int  n = graph.size();
        end_mask = (1<<n)-1;
        memset(dp, 0, sizeof(dp));
        
        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++){
            ans = min(ans, solve(i, end_mask, graph));
        }
        return ans;
    }
};