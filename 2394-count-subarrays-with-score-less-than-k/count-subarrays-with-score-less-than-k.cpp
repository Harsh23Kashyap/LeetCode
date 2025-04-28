class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum=0;

        long long c=0;

        int l=0,r=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            long long len=r-l+1;
            long long ans=sum*len;
            
            if(ans<k){
                // cout<<sum<<" "<<len<<" "<<ans<<endl;
                c+=len;
                // cout<<c<<endl;
        }
            while(l<=r and ans>=k){
                long long len=r-l+1;
                long long ans=sum*len;
                
                if(ans<k){
                    c+=len;
                    // cout<<sum<<" "<<len<<" "<<ans<<endl;
                    break;
                }
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return c;
    }
};