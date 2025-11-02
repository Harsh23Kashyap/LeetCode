class Solution {
public:
    void check(vector<vector<int>> &matrix, int i, int j, int dir){
       
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size()){
            return ;
        }
        if(matrix[i][j]==1 or matrix[i][j]==2){
            return;
        }
        matrix[i][j]=0;
       if(dir==1){
            check(matrix,i+1,j,dir);
       }
        if(dir==2){
            check(matrix,i,j+1,dir);
       } 
       if(dir==3){
            check(matrix,i-1,j,dir);
       }
       if(dir==4){
            check(matrix,i,j-1,dir);
       }

        matrix[i][j]=0;
       



    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int> (n,-1));

        for(auto it:guards)
        matrix[it[0]][it[1]]=1;
        for(auto it:walls)
        matrix[it[0]][it[1]]=2;

        for(auto it:guards)
        {
            int i=it[0],j=it[1];
           check(matrix,i+1,j,1);
            check(matrix,i,j+1,2);
            check(matrix,i-1,j,3);
           check(matrix,i,j-1,4);
            // }
        }
    int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-1)
                c++;
            }
        }
        return c;

    }
};