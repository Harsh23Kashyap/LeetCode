class Solution {
public:
    bool possible(vector<vector<int>>& grid, int i, int j)
    {
        //cout<<"runs"<<endl;
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())
            return false;
        //cout<<"runs1"<<endl;
        if(grid[i][j]!=1)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> rotten;
        int cnt=0;
        vector<pair<int,int>> dir;
        dir.push_back({-1,0});
         dir.push_back({0,-1});
         dir.push_back({1,0});
         dir.push_back({0,1});
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    rotten.push({i,j});
                if(grid[i][j]!=0)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
        if(cnt-rotten.size()==0)
            return 0;
        int d=-1;
        while(!rotten.empty())
        {
            int k=rotten.size();
            cout<<k<<endl;
            cnt-=k;
            while(k--)
            {
                pair<int,int> co=rotten.front();
                //cout<<"Current"<<co.first<<","<<co.second<<endl;
                rotten.pop();
                for(int i=0;i<4;i++)
                {
                   
                    pair<int,int> curr=make_pair(co.first+dir[i].first,co.second+dir[i].second);
                     //cout<<curr.first<<","<<curr.second<<endl;
                    if(possible(grid,curr.first,curr.second))
                    {
                        //cout<<"Push - "<<curr.first<<","<<curr.second<<endl;
                        grid[curr.first][curr.second]=2;
                        rotten.push(curr);
                        //cout<<"pushed"<<endl;
                    }
                    //cout<<i<<endl;
                   
                }
                
            }
            
            d++;
            cout<<cnt<<" "<<d<<endl;
        }
        return cnt==0?d:-1;
    }
};