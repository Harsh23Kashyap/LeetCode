class Solution {
public:
    int pass(int i, int j, vector<int>& nums, bool p1){
        if(i>j)
            return 0;
        
        if(p1){
            int op1=max(nums[i]+pass(i+1,j,nums,false), nums[j]+pass(i,j-1,nums,false));
        return op1;
        }
        else{
            int op2=min(-nums[i]+pass(i+1,j,nums,true), -nums[j]+pass(i,j-1,nums,true));
        return op2;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int res= pass(0,j,nums,true);
        return res>=0;

    }
};