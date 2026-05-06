class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();

        vector<vector<char>> ng(n, vector<char> (m,'.'));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ng[j][m-i-1]=grid[i][j];
            }
        }

        for(int i=0;i<ng[0].size();i++){
            for(int j=ng.size()-1;j>=0;j--){
                int stone=0;
                int st=j;
                while(j>=0 and ng[j][i]!='*'){
                    if(ng[j][i]=='#')
                        stone++;
                    j--;
                }
                if(stone>0){
                    for(int cp=st;cp>j;cp--){
                        if(stone>0)
                        {
                            ng[cp][i]='#';
                            stone--;
                        }
                        else{
                             ng[cp][i]='.';
                        }
                    }
                }
            }
        }
        return ng;
        

    }
};