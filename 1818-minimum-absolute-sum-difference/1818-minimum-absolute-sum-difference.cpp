class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> dp(nums1.size(),0);
        int ind=0,maxi=INT_MIN;
        int sum=0;
        int m=1e9+7;
        
        for(int i=0;i<nums1.size();i++)
        {
            dp[i]=abs(nums1[i]-nums2[i]);
            sum=(sum+dp[i])%m;
        }
        
        vector<int> copy(nums1.size(),INT_MAX);
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums1.size();i++)
        {
            int j=lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(j!=0 and j!=nums1.size())
                copy[i]=min(abs(nums1[j]-nums2[i]),abs(nums1[j-1]-nums2[i]));
            
            else if(j==0)
                copy[i]=abs(nums1[j]-nums2[i]);
            else if(j==nums1.size())
                 copy[i]=abs(nums1[j-1]-nums2[i]);
            
        }
        
        int val=INT_MIN;
        for(int i=0;i<dp.size();i++)
        {
            val=max(abs(dp[i]-copy[i]),val);
        }
        
        sum=(sum-val+m)%m;
        return sum;
        
    }
};