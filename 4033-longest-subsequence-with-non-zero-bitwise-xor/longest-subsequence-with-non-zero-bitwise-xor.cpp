class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int a=0;
        for(auto it:nums){
            a=a^it;
        }

        if(a!=0)
            return nums.size();
        else{
            
            for(int i=0;i<nums.size();i++){
                if(a^nums[i]!=0)
                    return nums.size()-1;
            }
            

        }
        return 0;
    }
};