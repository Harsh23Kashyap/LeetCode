class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) 
    {
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++)
            u[nums[i]]=i;
        
        
        for(int i=0;i<operations.size();i++)
        {
            auto itr=u.find(operations[i][0]);
            int index=itr->second;
            cout<<index<<endl;
            u[operations[i][1]]=index;
            nums[index]=operations[i][1];
        }
        return nums; 
    }
};