class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        bool isEven=nums[0]%2==0;
        for(int i=1;i<nums.size();i++){
           if(isEven){
            if(nums[i]%2==0)
            return false;
           
           }
            else{
                 if(nums[i]%2!=0)
            return false;
           
            }
            isEven=!isEven;
        }
        return true;
    }
};