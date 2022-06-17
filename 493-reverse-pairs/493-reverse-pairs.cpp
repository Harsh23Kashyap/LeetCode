class Solution {
public:
    int c;
    void inverse(vector<int>& nums, int start, int end, int mid)
    {
        int l = start, r = mid + 1;
        while(l <= mid and r <= end)
        {
            if((long)nums[l] > (long) 2 * nums[r])
            {
                c += (mid - l + 1);
                r++;
            }
            else
                l++;
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
        
    }
    
    void merge(vector<int>& nums, int s, int e)
    {
        
        if(s>=e)
            return;
        int m=(e+s)/2;
        merge(nums,s,m);
        merge(nums,m+1,e);
        inverse(nums,s,e,m);
        return;
    }
              
              
              
    int reversePairs(vector<int>& nums) 
    {
        if(!nums.size())
            return 0;
        c=0;
        cout<<nums.size();
        merge(nums,0,nums.size()-1);
        return c;
        
    }
};