class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++)
            u[nums[i]]++;
        
        int sum=0;
        for(auto i:u)
        {
            if(i.second==1)
                sum+=i.first;
        }
        return sum;
        
    }
};