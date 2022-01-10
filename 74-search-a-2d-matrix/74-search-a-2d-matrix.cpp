class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=matrix.size();
            int col=matrix[0].size();
        int i=0,j=col-1;
        if(matrix[0][0]>target || matrix[row-1][col-1]<target) return false;
        cout<<"yes";
        for (i=0;i<row;i++)
            if(matrix[i][j]>=target)
                break;
        int start=0,end=col-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(matrix[i][mid]==target) return true;
            else if(matrix[i][mid]<target) start=mid+1;
            else end=mid-1;
                
        }
        return false;
    }
};