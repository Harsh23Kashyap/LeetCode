class Solution {
public:
    void combine(vector<vector<int>>& ans, int n, int k, int i,int c,vector<int>& v )
    {
        if(c==k)
        {
            //cout<<"runs"<<endl;
            ans.push_back(v);
            return ;
            
        }
        if(i==n+1)
            return;
        for(int j=i;j<=n;j++)
        {
            //cout<<"Putting - "<<j<<endl;
            v.push_back(j);
            combine(ans,n,k,j+1,c+1,v);
            //cout<<"Pops"<<endl;
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        combine(ans,n,k,1,0,v);
        return ans;
    }
};