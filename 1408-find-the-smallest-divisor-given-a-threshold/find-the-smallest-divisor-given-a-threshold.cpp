class Solution {
public:
    int rem(vector<int>& nums, int div)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=(nums[i]+div-1)/div;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int best=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int temp=rem(nums,mid);
            //cout<<mid<<" - "<<temp<<endl;
            if(temp<=threshold)
            {
                best=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return best;
        
    }
};