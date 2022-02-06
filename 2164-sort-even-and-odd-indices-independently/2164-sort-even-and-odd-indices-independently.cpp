class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector<int>even;
        vector<int>odd;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        int j=0,k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
                nums[i]=odd[j++];
            else
                nums[i]=even[k++];
        }
        return nums;
    }
};