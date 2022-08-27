class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        set<int> s;
        unordered_map<int,int> u;
        
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
                
        }
        int ans=INT_MIN;
    
        for(int start=0;start<n;start++)
        { 
            for(int end=start;end<n;end++)
            {
                int prefsum=0;
                //cout<<start<<" , "<<end<<endl;
                set<int>s;
                s.insert(0);
                for(int i=0;i<m;i++)
                {
                    prefsum+=matrix[i][end];
                    if(start!=0)
                        prefsum-=matrix[i][start-1];
                    //cout<<prefsum<<endl;
                    auto it=s.lower_bound(prefsum-k);
                    if(it!=s.end())
                        ans=max(ans,prefsum-*it);
                    s.insert(prefsum);
                }
                
            }
        }
        return ans;
        
    }
};