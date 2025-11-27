class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> ps;
        ps.push_back(0);
        ps.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            ps.push_back(nums[i]+ps.back());

        long long ans=LONG_MIN;
         vector<long long> bm(k,LLONG_MAX);
        //  cout<<"hi"<<endl;
        for(int i=0;i<=nums.size();i++){
           int rem=i%k;
           if(bm[rem]!=LLONG_MAX){
            long long possans=ps[i]-bm[rem];
            if(ans<possans)
                ans=possans;
           }
           if(bm[rem]>ps[i])
           bm[rem]=ps[i];
        }
        return ans;
        
    }
};