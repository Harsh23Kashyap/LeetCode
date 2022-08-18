class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long ans=0;
        int prev=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            int k=(int)ceil(nums[i]*1.0/prev);
            prev=(k==0)?nums[i]:nums[i]/k;
            
            //cout<<nums[i]<<" "<<k<<" ->"<<prev<<endl;
            ans+=(k==0)?0:(k-1);
        }
        return ans;
        
    }
};