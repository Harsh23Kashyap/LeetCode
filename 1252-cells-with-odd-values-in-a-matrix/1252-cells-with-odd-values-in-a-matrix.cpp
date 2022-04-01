class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) 
    {
        vector<vector<int>> vec( m , vector<int> (n, 0));
        
        
        for(int i=0;i<indices.size();i++)
        {
            int row=indices[i][0];
            int col=indices[i][1];
            
            for(int i=0;i<n;i++)
                vec[row][i]++;
            for(int i=0;i<m;i++)
                vec[i][col]++;
        }
        //cout<<"Hi";
        int c=0;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                if(vec[i][j]&1)
                    c++;
            }
        }
        return c;
        
    }
};