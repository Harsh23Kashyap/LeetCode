class Solution {
public:
vector<int> dx={0,0,1,-1};
vector<int> dy={1,-1,0,0};
typedef pair<int, pair<int,int>> pp;
    int minCost(vector<vector<int>>& grid) {
        

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dp[0][0]=0;

        while(!pq.empty()){
            auto [cost,dim]=pq.top();
            auto [x,y]=dim;
            // cout<<x<<" "<<y<<endl;
            pq.pop();
            if(dp[x][y]<cost)
                continue;
            
            for(int k=1;k<=4;k++){
                int currcost=(grid[x][y]==k)?0:1;
                int nx=dx[k-1]+x;
                int ny=dy[k-1]+y;
                if(not(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size()))
                    continue;
                if(dp[nx][ny]>cost+currcost){
                    dp[nx][ny]=cost+currcost;
                    pq.push({cost+currcost,{nx,ny}});
                }
            }

            
        }
        return dp[grid.size()-1][grid[0].size()-1];

    }
};