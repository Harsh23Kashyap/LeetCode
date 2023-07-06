class Solution {
public:
    bool possible(vector<int> pref, int t, int m)
    {
        if(pref[m-1]>=t)
            return true;
        for(int i=m;i<pref.size();i++)
        {
            if(pref[i]-pref[i-m]>=t)
                return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=1,h=nums.size();
        vector<int> pref(nums.size(),0);
        int s=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            pref[i]=s;
        }
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(possible(pref,target,m))
            {
                h=m-1;
                ans=min(ans,m);
            }
            else
                l=m+1;
        }
        return ans!=INT_MAX?ans:0;
    }
};