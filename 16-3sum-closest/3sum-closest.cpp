class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) 
   {
        long long ans = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<nums.size()-2 ; i++)
        {
            if(i>0 && nums[i-1]==nums[i]) continue;
            int j = i+1,k = nums.size()-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target)
                    return target;
                else if(sum<target)
                {
                    ans = (abs(sum-target)<abs(ans-target))?sum:ans;
                    j++;
                    while(j<k && nums[j-1]==nums[j])j++;
                }
                else
                {
                    ans = (abs(sum-target)<abs(ans-target))?sum:ans;
                    k--;
                    while(k>j && nums[k+1]==nums[k]) k--;
                }
            }
        }
        return ans;
    }
};