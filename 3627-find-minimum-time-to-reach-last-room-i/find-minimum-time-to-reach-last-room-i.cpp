class Solution {
public:
    typedef pair<int,int> pp;
    typedef pair<int,pp> ppp;
    int minimumTime(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        priority_queue<ppp,vector<ppp>, greater<ppp>> pq;
        unordered_set<int> u;
        pq.push({0,{0,0}});
        vector<int> dx{-1,0,1,0,-1};
        while(!pq.empty())
        {
            auto [time,cord]=pq.top();
            auto [cx,cy]=cord;
            cout<<cx<<" "<<cy<<" "<<time<<endl;
            pq.pop();
            if(cx==m-1 and cy==n-1)
                return time;
            if(u.find(cx*n+cy)!=u.end())
                continue;
            u.insert(cx*n+cy);
            for(int i=0;i<4;i++)
            {
                int nx=cx+dx[i];
                int ny=cy+dx[i+1];
                // int nt=time+1;
                if(nx<0 or ny<0 or nx>=grid.size() or ny>=grid[0].size())
                    continue;
                int maxtime=max(time+1,grid[nx][ny]+1);
                pq.push({maxtime,{nx,ny}});
                
            }
        }
        
        return -1;
    }
            
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return minimumTime(moveTime);
    }
};