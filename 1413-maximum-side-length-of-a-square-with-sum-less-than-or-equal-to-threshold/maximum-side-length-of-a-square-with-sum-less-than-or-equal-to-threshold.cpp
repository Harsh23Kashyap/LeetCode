class Solution {
public:
    bool possible(int len, vector<vector<int>>& ps, int threshold, int m, int n) {
        for (int i = 0; i + len <= m; i++) 
        {
            for (int j = 0; j + len <= n; j++) 
            {
                int tosubtract=ps[i][j+len]+ps[i+len][j]-ps[i][j];
                int sum = ps[i+len][j+len] - tosubtract;
                        
                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ps(m+1,vector<int> (n+1,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ps[i+1][j+1]=mat[i][j]+ps[i+1][j]+ps[i][j+1]-ps[i][j];
            }
        }
        // for(int i=0;i<m+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         cout<<ps[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        int low=0,high=min(m,n);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,ps,threshold,m,n)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};