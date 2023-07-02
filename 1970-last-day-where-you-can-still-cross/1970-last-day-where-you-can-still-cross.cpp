class Solution {
public:
    vector<int> dirx={-1,0,1,0};
    vector<int> diry={0,-1,0,1};
    bool can(int d, vector<vector<int>> cell, int r, int c)
    {
        vector<vector<int>> days(r,vector<int>(c,0));
        for(int i=0;i<d;i++)
            days[cell[i][0]-1][cell[i][1]-1]=1;
        // cout<<"EMptyyyy"<<endl;
        queue<pair<int,int>> q;
        for(int i=0;i<c;i++)
        {
            if(days[0][i]==0)
            {
                q.push({0,i});
                days[0][i]=-1;
            }
        }
        // cout<<"empty"<<endl;
        while(!q.empty())
        {
            auto it=q.front();
            // cout<<it.first<<" "<<it.second<<endl;
            q.pop();
            if(it.first==r-1)
                return true;
            for (int i=0;i<4;i++)
            {
                int x=it.first+dirx[i],y=it.second+diry[i];
                if(x>=0 and y>=0 and x<r and y<c and days[x][y]==0)
                {
                    days[x][y]=-1;
                    q.push({x,y});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start=1,end=cells.size();
        int ans=1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            cout<<mid<<endl;
            if(can(mid,cells,row,col))
            {
                ans=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
    }
};