class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int row=rowSum.size(),col=colSum.size();
        vector<vector<int>> ans;
        for(int i=0;i<row;i++)
        {
            vector<int> v(col,0);
            ans.push_back(v);
        }
        int rs=0,cs=0;
        for(int i=rs;i<row;i++)
        {
            for(int j=cs;j<col;j++)
            {
                if(rowSum[i]>colSum[j])
                {
                    ans[i][j]=colSum[j];
                    rowSum[i]-=colSum[j];
                    colSum[j]=0;
                    cs++;
                }
                else
                {
                    ans[i][j]=rowSum[i];
                    colSum[j]-=rowSum[i];
                    rowSum[i]=0;
                    break;
                }
            }
        }
        return ans;
    }
};