class Solution {
public:
    // unordered_set<pair<int,int>> u;
    int serach_more(vector<int> &nums, int upper, int i)
    {
        int l=i+1,h=nums.size()-1;
        int maxi=INT_MIN;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]+nums[i]<=upper){
                maxi=max(maxi,m);
                l=m+1;
            }
            else
                h=m-1;
        
            
            
        }
        return maxi;
    }
     int serach_less(vector<int> &nums, int lower, int i)
    {
        int l=i+1,h=nums.size()-1;
        int mini=INT_MAX;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]+nums[i]>=lower){
                mini=min(mini,m);
                h=m-1;
                
            }
            else
                l=m+1;
        
            
            
        }
        return mini;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums.size()-1;
        
        long long  c=0;
        for(auto it:nums)
            cout<<it<<" ";
        cout<<endl;
        for(int i=0;i<nums.size();i++)
        {
            int upper_ind=serach_more(nums,upper,i);
            
                
            int lower_ind=serach_less(nums,lower,i);
            // cout<<i<<" "<<nums[i]<<" "<<upper_ind<<" "<<lower_ind<<endl;
            if(upper_ind!=INT_MIN and lower_ind!=INT_MAX)
                c+=(upper_ind-lower_ind+1);
        }
        return c;
    }
};