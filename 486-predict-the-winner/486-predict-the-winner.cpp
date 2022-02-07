class Solution {
public:
    int answer(vector<int>& nums,int start,int end, int turn,int add)
    {
        if(start==end)
            return nums[start]*turn;
        
        if(turn==1)
        {
            int chooseFirst=nums[start]+answer(nums,start+1,end,-1,add);
            int chooseLast=nums[end]+answer(nums,start,end-1,-1,add);
            return add+max(chooseFirst,chooseLast);
        }
        int chooseFirst=-nums[start]+answer(nums,start+1,end,1,add);
        int chooseLast=-nums[end]+answer(nums,start,end-1,1,add);
        return add+min(chooseFirst,chooseLast);
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
        int score=answer(nums,0,nums.size()-1,1,0);
        if(score>=0)
            return true;
        return false;
        
    }
};