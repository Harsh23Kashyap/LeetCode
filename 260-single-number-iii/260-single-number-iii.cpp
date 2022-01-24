class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xored=nums[0];
        for(int i=1;i<nums.size();i++)
            xored=xored^nums[i];
        
        int ind=0;
        int copyxor=xored;
        while(copyxor)
        {
            if(copyxor&1)
                break;
            ind++;
            copyxor=copyxor>>1;
        }
        int first=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]>>ind)&1)
                first=first^nums[i];
        }
        xored=xored^first;
        vector<int> v{xored,first};
        return v;
        
    }
};