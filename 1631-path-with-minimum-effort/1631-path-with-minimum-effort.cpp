class Solution {
public:
    bool boundary(int x,int y, int limx,int limy)
    {
        if(x>=0 and y>=0 and x<limx and y<limy)
            return true;
        return false;
    }
    void possible(vector<vector<int>>& heights, int size, int i, int j,vector<vector<bool>>& visited)
    {
        //cout<<i<<" , "<<j<<endl;
        if(i==heights.size()-1 and j==heights[0].size()-1)
        {
            //cout<<"runs"<<endl;
            visited[i][j]=true;
            return ;
        }
        if(i>heights.size() or j>heights[0].size() or i<0 or j<0)
        {
            return ;
        }
        if(boundary(i-1,j,heights.size(),heights[0].size()) and !visited[i-1][j] and abs(heights[i-1][j]-heights[i][j])<=size)
        {
            visited[i-1][j]=true;
               possible(heights,size,i-1,j,visited);
         }
           if(boundary(i+1,j,heights.size(),heights[0].size()) and !visited[i+1][j] and abs(heights[i+1][j]-heights[i][j])<=size)
        {
            visited[i+1][j]=true;
               possible(heights,size,i+1,j,visited);
         }
              if(boundary(i,j-1,heights.size(),heights[0].size()) and !visited[i][j-1] and abs(heights[i][j-1]-heights[i][j])<=size)
        {
            visited[i][j-1]=true;
               possible(heights,size,i,j-1,visited);
         }
                 if(boundary(i,j+1,heights.size(),heights[0].size()) and !visited[i][j+1] and abs(heights[i][j+1]-heights[i][j])<=size)
        {
            visited[i][j+1]=true;
               possible(heights,size,i,j+1,visited);
         }
    }
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int left=0;
        int right=1e6;
        int best=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            //cout<<mid<<endl;
            vector<vector<bool>> visited(heights.size(),vector<bool> (heights[0].size(), false));
            visited[0][0]=true;
            possible(heights,mid,0,0, visited);
            if(visited[visited.size()-1][visited[0].size()-1])
            {
                best=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return best;
        
    }
};