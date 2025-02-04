class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int sum=0;
        int csum=0;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])
            {
                csum+=nums[i];
            }
            else
            {
                csum+=nums[i];
                sum=max(sum,csum);
                csum=0;
            }
        }
        csum+=nums.back();
        return max(sum,csum);
    }
};