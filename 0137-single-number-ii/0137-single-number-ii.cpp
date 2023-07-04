class Solution {
public:
    int count(vector<int>& nums, int j)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]>>j)&1)
                c++;
        }
        cout<<"At position"<<j+1<<" - "<<c<<endl;
        return c;
    }
    int setBit(int n,int i)
    {
        int mask=1<<i;
        int ans=n|mask;
        return ans;
    }
    int singleNumber(vector<int>& nums) 
    {
        int num=0;
        for(int i=0;i<32;i++)
        {
            int add=count(nums,i);
            add=add%3;
            if(add>0)
                num=setBit(num,i);
            
        }
        return num;
    }
};