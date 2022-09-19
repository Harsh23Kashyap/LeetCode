//#define vec vector<int> 
class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) 
    {
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        int r=hm.size(),c=hm[0].size();
       
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> > pq;

        for(int i=0;i<r;i++)
        {
           // cout<<i<<" , "<<0<<endl;
            pq.push({hm[i][0],i,0});
            hm[i][0]=-1;
             // cout<<i<<" , "<<c-1<<endl;
            pq.push({hm[i][c-1],i,c-1});
            hm[i][c-1]=-1;
        }
        for(int i=0;i<c;i++)
        {
            pq.push({hm[0][i],0,i});
            hm[0][i]=-1;
            pq.push({hm[r-1][i],r-1,i});
            hm[r-1][i]=-1;
        }
        int store=0;
        while(!pq.empty())
        {
            auto cell=pq.top();
            int height=cell[0],x=cell[1],y=cell[2];
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int newX=x+dx[i],newY=y+dy[i];
                if(newX<0 or newX>=r or newY<0 or newY>=c or hm[newX][newY]==-1)
                    continue;
                
                if(hm[newX][newY]<height)
                {
                    store+=height-hm[newX][newY];
                    pq.push({height,newX,newY});
                }
                else
                    pq.push({hm[newX][newY],newX,newY});
                
                hm[newX][newY]=-1;
                
            }
        }
        return store;
        
    }
};