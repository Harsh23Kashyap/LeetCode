class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        for(int i=0;i<grid.size();i++){
            vector<int> ch;
            
            int l=i;
            for(int j=0;j<grid.size() and l<grid.size();j++,l++){
                // cout<<grid[l][j]<<" ";
                ch.push_back(grid[l][j]);
            }
            int k=0;
            l=i;
            // cout<<endl;
            sort(ch.rbegin(),ch.rend());
             for(int j=0;j<grid.size() and l<grid.size();j++,l++){
               grid[l][j]=ch[k++];
            }
        }
        for(int i=1;i<grid.size();i++){
            vector<int> ch;
            
            int l=i;
            for(int j=0;j<grid.size() and l<grid.size();j++,l++){
                // cout<<grid[j][l]<<" ";
                ch.push_back(grid[j][l]);
            }
            int k=0;
            l=i;
            // cout<<endl;
            sort(ch.begin(),ch.end());
             for(int j=0;j<grid.size() and l<grid.size();j++,l++){
               grid[j][l]=ch[k++];
            }
        }
        return grid;
    }
};