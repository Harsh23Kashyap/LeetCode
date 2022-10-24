class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        vector<int> column;
         for(int i=0;i<matrix[0].size();i++)
         {
             int maxi=0;
             for(int j=0;j<matrix.size();j++)
             {
                 maxi=max(maxi,matrix[j][i]);
             }
            // cout<<maxi<<" ";
             column.push_back(maxi);
         }
        
        //cout<<endl<<endl;
        vector<pair<int,int>> row;
         for(int i=0;i<matrix.size();i++)
         {
             int maxi=INT_MAX;
             int ind=0;
             for(int j=0;j<matrix[0].size();j++)
             {
                 if(maxi>matrix[i][j])
                 {
                    maxi=matrix[i][j];
                     ind=j;
                 }
             }
             //cout<<maxi<<","<<ind<<"  ";
             row.push_back({maxi,ind});
         }
        //cout<<endl;
        
        vector<int> ans;
        for(int i=0;i<row.size();i++)
        {
            int ind=row[i].second;
            if(row[i].first==column[row[i].second])
                ans.push_back(row[i].first);
        }
        return ans;
        
        
    }
};