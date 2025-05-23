class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> r;
        unordered_map<int,int> c;
        int tc=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    {
                        r[i]++;
                        c[j]++;
                        tc++;
                    }
            }
        }
        int cc=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    {
                         if(r[i]==1 and c[j]==1)
                                cc++;
                    }
            }
        }
        // for(auto it:grid){
        //    if(r[it[0]]==1 and c[it[1]]==1)
        //    cc++;
        // }
        cout<<cc<<endl;
        return tc-cc;
        
    }
};