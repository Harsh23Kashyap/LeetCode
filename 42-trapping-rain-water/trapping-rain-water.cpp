class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],height[i]);
        
        int tot=0;
        for(int i=1;i<n-1;i++)
        {
            //cout<<i<<" - "<<left[i]<<" "<<right[i]<<endl;
            int curr=min(left[i],right[i]);
            tot+=max(0,curr-height[i]);
        }
        return tot;
        
    }
};