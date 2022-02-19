class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        vector<int> sorted(nums.size());
        sort(nums.begin(), nums.end());
        int i=1;
        int j=nums.size()-1;
        while(i<nums.size())
        {
            sorted[i]=nums[j];
            j--;
            i+=2;
        }
        i=0;
        while(i<nums.size())
        {
            sorted[i]=nums[j];
            j--;
            i+=2;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=sorted[i];
        }
    }
};