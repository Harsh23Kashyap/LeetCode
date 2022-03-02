class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        vector<vector<int>> copy=img;
        int m=img.size();
        int n=img[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=1;
                int sum=copy[i][j];
                if(isValid(i-1,j-1,m,n)) 
                {
                    sum=sum+copy[i-1][j-1]; 
                    count++;
                }
                if(isValid(i-1,j  ,m,n)) 
                {
                    sum=sum+copy[i-1][j]; 
                    count++;
                }
                if(isValid(i-1,j+1,m,n)) 
                {
                    sum=sum+copy[i-1][j+1]; 
                    count++;
                }
                if(isValid(i  ,j-1,m,n)) 
                {
                    sum=sum+copy[i  ][j-1]; 
                    count++;
                }
                if(isValid(i  ,j+1,m,n)) 
                {
                    sum=sum+copy[i][j+1]; count++;
                }
                if(isValid(i+1,j-1,m,n)) 
                {
                    sum=sum+copy[i+1][j-1]; 
                    count++;
                }
                if(isValid(i+1,j  ,m,n)) 
                {
                    sum=sum+copy[i+1][j]; 
                    count++;
                }
                if(isValid(i+1,j+1,m,n)) 
                {
                    sum=sum+copy[i+1][j+1]; 
                    count++;
                }
                img[i][j]=sum/count;
            }
        }
        return img;
    }
    bool isValid(int x,int y,int m,int n)
    {
        return (x>=0 and x<m and y>=0 and y<n);
    }
};