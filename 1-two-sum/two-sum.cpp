class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int> u; 
        for(int i=0;i<nums.size();i++)
        {
            if(u.find(target-nums[i])!=u.end() and i!=u[target-nums[i]])
            {
                // cout<<"FOund"<<endl;
                // cout<<i<<endl;
                // cout<<u[target-nums[i]]<<endl;
                return {i,u[target-nums[i]]};
            }
            u[nums[i]]=i;
        }
        return {};
    }
};