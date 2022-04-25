class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int high=2;high<nums.size();high++)
        {
            int low=0;
            int mid=high-1;
            while(low<mid)
            {
                if(nums[low]+nums[mid]>nums[high])
                {
                    count+=(mid-low);
                    mid--;
                }
                else
                    low++;
            }
            cout<<count<<endl;
        }
        return count;
        
    }
};