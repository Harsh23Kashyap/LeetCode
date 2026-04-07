class Solution {
public:
typedef pair<int,pair<int,int>> pp;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        priority_queue<pp,vector<pp>, greater<pp>> pq;
        vector<vector<int>> dp(m, vector<int> (n,INT_MAX));
        pq.push({0,{0,0}});
        dp[0][0]=0;

        while(!pq.empty()){
            auto [cost,dir]=pq.top();
            int x=dir.first,y=dir.second;
            pq.pop();

            if(cost>dp[x][y])
                continue;

            
            for(int k=1;k<=4;k++){

                int nc=(grid[x][y]==k)?0:1;
                int nx=dx[k-1]+x,ny=dy[k-1]+y;
                if(nx<0 or ny<0 or nx>=m or ny>=n)
                    continue;
                if(nc+cost<dp[nx][ny]){
                    dp[nx][ny]=nc+cost;
                    pq.push({nc+cost,{nx,ny}});
                }
            }
        }
        return dp[m-1][n-1];

    }
};