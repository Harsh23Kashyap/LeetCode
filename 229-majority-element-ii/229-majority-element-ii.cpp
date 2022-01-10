class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        set<int> s;
        sort(nums.begin(),nums.end());
        int count=0,no=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==no)
                count++;
            else
            {
                no=nums[i];
                count=1;
            }
            if(count>nums.size()/3) s.insert(no);
        }
        vector<int> v{s.begin(),s.end()};
        return v;
    }
};