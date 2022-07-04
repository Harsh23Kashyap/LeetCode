class Solution {
public:
    int candy(vector<int>& greedy) 
    {
        int n=greedy.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            if(greedy[i]>greedy[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1;
        }
        right[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(greedy[i]>greedy[i+1])
                right[i]=right[i+1]+1;
            else
                right[i]=1;
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
           cnt+=max(left[i],right[i]);
        }
        return cnt;
        
        
    }
};