class Solution {
public:
    void generate(int i,int k,vector<int> &temp,vector<vector<int>> &com,int lim)
    {
        if(temp.size()==k)
        {
            com.push_back(temp);
            return;
        }
        if(i==lim)
            return;
        if((lim-i)<k-temp.size())
            return;
        
        //include
        temp.push_back(i);
        generate(i+1,k,temp,com,lim);
        //exclude
        temp.pop_back();
        generate(i+1,k,temp,com,lim);
        return;
    }
    int maximumRows(vector<vector<int>>& mat, int cols) 
    {
        int n=mat.size(),m=mat[0].size();
        //int possible=power(2,m)-1;
        vector<vector<int>> comb;
        int maxi=0;
        vector<int> temp;
        generate(0,m-cols,temp,comb,m);
//         for(int i=0;i<comb.size();i++)
//         {
//             for(int j=0;j<comb[i].size();j++)
//                 cout<<comb[i][j]<<" ";
//             cout<<endl;
            
//         }
        for(int i=0;i<comb.size();i++)
        {
            int ans=0;
            unordered_set<int> st;
            for(int j=0;j<comb[i].size();j++)
            {
                
               int col=comb[i][j];
               // cout<<col<<" ";
                for(int k=0;k<n;k++)
                {
                    if(mat[k][col]==1)
                    {
                        st.insert(k);
                        //break;
                    }
                }
                    
            }
            
            
            
            ans=n-st.size();
            // cout<<endl;
            // cout<<"Ans-"<<ans<<endl;
            maxi=max(ans,maxi);
            
        }
       
        return maxi;
    }
};