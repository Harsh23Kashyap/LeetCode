class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        int even=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
                even+=nums[i];
        }
        //cout<<even<<endl;
        for(int i=0;i<queries.size();i++)
        {
            int ind=queries[i][1];
            int val=queries[i][0];
            
            //cout<<"First   ";
            if(nums[ind]%2==0)
                even-=nums[ind];
            cout<<even;
            nums[ind]+=val;
            if(nums[ind]%2==0)
                even+=nums[ind];
            //cout<<"\t"<<even<<endl;
            
            ans.push_back(even);
            
        }
        return ans;
    }
};