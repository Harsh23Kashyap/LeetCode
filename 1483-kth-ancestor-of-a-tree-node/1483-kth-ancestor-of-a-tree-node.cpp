class TreeAncestor {
public:
    int m=17;
    vector<vector<int>> dp;
        
    TreeAncestor(int n, vector<int>& parent) 
    {
        dp.resize(m, vector<int>(n ,0));

        for(int i=0;i<n;i++)
            dp[0][i]=parent[i];
        
        for(int i=1;i<m;i++)
        {
            //cout<<i<<endl;
            for(int j=0;j<n;j++)
            {
                int val=dp[i-1][j];
                dp[i][j]=(val==-1)?-1:dp[i-1][val];
            }
            
        }
        
//          for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//                 cout<<dp[i][j]<<" ";
//              cout<<endl;
//         }
        
    }
    
    int getKthAncestor(int node, int k) 
    {
        int i=0;
        while(k>0)
        {
            if(k&1)
                node=dp[i][node];
            if(node==-1)
                return -1;
            k=k>>1;
            i++;
        }
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */