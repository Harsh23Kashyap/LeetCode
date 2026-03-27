class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        // vector<vector<int> copy=mat;
       int m=mat.size(),n=mat[0].size();
       k=k%n;
       for(int i=0;i<m;i++){
        vector<int> sz(n,0);
            if(i%2==0)
            {
                for(int j=0;j<n;j++){
                    int newPos=(j-k+n)%n;
                    sz[newPos]=mat[i][j];

                    if(mat[i][newPos]!=sz[newPos])
                    return false;
                }
            }
            else 
            {
                for(int j=0;j<n;j++){
                    int newPos=(j+k)%n;
                    sz[newPos]=mat[i][j];

                    if(mat[i][newPos]!=sz[newPos])
                    return false;
                }
            }
       }
       return true;
    }
};