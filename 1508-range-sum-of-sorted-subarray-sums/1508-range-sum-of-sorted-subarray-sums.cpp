#define ll long long
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        int mod=1e9+7;
        vector<ll> csum={nums[0]};
        vector<ll> sub={nums[0]};
        for(int i=1;i<nums.size();i++)
        {
            csum.push_back(nums[i]+csum[i-1]);
            sub.push_back(nums[i]+sub[i-1]);
        }
        for(int i=0;i<csum.size();i++)
        {
            for(int j=i+1;j<csum.size();j++)
            {
                sub.push_back(csum[j]-csum[i]);
            }
        }
        sort(sub.begin(),sub.end());
        // for(int i:sub)
        //     cout<<i<<" ";
        // cout<<endl;
        ll s=0;
        for(int i=left-1;i<right;i++)
            s=((ll)s%mod+(ll)sub[i]%mod)%mod;
        
        return s%mod;
        
        
    }
};