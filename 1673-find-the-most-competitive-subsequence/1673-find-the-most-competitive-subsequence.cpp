class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        stack<int> s;
        int si=0;
        for(int i=0;i<nums.size();i++)
        {
           while(!s.empty() and s.top()>nums[i] and s.size()+nums.size()-i>k)
                    s.pop();
                //cout<<"\t runs"<<s.top()<<endl;
                s.push(nums[i]);
        }
        
        
        vector<int> ans(k,0);
        while(s.size()>k)
        {
            s.pop();
        }
        int i=k-1;
        while(!s.empty())
        {
            ans[i--]=s.top();
            s.pop();
        }
        return ans;
    }
};