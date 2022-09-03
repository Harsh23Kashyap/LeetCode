class Solution {
public:
    int power(int x, int y)
    {
        int result = 1;
        while (y > 0) 
        {
          if(y&1==1) // y is odd
          {
            result=result*x;
          }
          x=x*x;
          y=y>>1; // y=y/2;
        }
        return result;
    }
    int maximumRows(vector<vector<int>>& mat, int cols) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int possible=power(2,m)-1;
        vector<vector<int>> vp(possible+1,vector<int>(m,0));
        int i=0;
        while(i<=possible)
        {
            int el=i;
            int j=0;
            while(j<m)
            {
                if((i&(1<<j))>=1)
                {
                    vp[i][j]=1;
                }
                j++;
            }
            i++;
        }
        int maxi=INT_MIN;
        i=0;
        while(i<=possible)
        {
            int cnt=0;
            set<int> st;
            int gnt=0;
            int j=0;
            while(j<m)
            {
                if(vp[i][j]==1)
                {
                    st.insert(j);
                    cnt++;
                }
                j++;
             }
            if(cnt==cols)
            {
                for(int i=0;i<n;i++)
                {
                    int check=0; 
                    for(int j=0;j<m;j++)
                    {
                        if(st.count(j)==0)
                        {
                            if(mat[i][j]==1) 
                                check=1;
                        }
                    }
                    if(check==0)
                        gnt++; 
                }
            } 
            maxi=max(maxi,gnt);
            i++;
        }
        if(maxi==INT_MIN)
            return 0;
        return maxi;
        
    }
};