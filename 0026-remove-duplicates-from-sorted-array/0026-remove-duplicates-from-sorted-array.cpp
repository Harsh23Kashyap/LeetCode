class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[j]!=nums[j-1])
            {
                nums[i]=nums[j-1];
                i++;
            }
        }
        return i;
    }
};