class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        //bool rs=f
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
        
    }
//     bool containsDuplicate(vector<int>& nums) 
//     {
//         sort(nums.begin(),nums.end());
//         for(int i=0,j=1;i<nums.size(),j<nums.size();)
//         {
//             if(nums[i]==nums[j])
//                 return true;
//             else
//             {
//                 i=j;
//                 j++;
//             }
//         }
//         return false;
        
//     }
};