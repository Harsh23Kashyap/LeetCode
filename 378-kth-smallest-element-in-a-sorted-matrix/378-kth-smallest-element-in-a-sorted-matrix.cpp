class Solution {
public:
    int rank(int num,vector<vector<int>>& matrix,int size)
    {
        int r=0;
        int i=0,j=size-1;
        while(i<size and j>=0)
        {
            if(matrix[i][j]>num)
            {
                j--;
            }
            else
            {
                r=r+j+1;
                i++;
            }
        }
        return r;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
//         vector<int> v;
//         for(int i=0;i<matrix.size();i++)
//         {
//             for(int j=0;j<matrix[i].size();j++)
//                 v.push_back(matrix[i][j]);
//         }
        
//         sort(v.begin(),v.end());
//         return v[k-1];
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high)
        {
            int mid=(low+high)/2;
            cout<<"Rank of "<<mid<<" - "<<rank(mid,matrix,n);
            
            if(rank(mid,matrix,n)<k)
            {
                low=mid+1;
            }
            else 
                high=mid-1;
            cout<<"         Low- "<<low<<endl;
        }
        return low;
    }
};