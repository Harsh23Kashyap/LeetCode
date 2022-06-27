class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        map<int,vector<int>> m;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                m[i-j].push_back(mat[i][j]);
            }
        }
        
        for(auto it:m)
        {
           
            vector<int> v=it.second;
             sort(v.begin(),v.end());
            m[it.first]=v;
            //cout<<it.first<<endl;
        }
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mat[i][j]=m[i-j][0];
                m[i-j].erase(m[i-j].begin());
            }
        }
        return mat;
        
    }
};