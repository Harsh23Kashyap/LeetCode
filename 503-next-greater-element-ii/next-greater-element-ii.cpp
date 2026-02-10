class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // nums.push_back(nums);
       
        stack<int> st;
        int n=nums.size();
         vector<int> ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]<=nums[i%n])
            st.pop();
            if(i<n){
                if(st.empty())
                    ans[i]=(-1);
                else
                ans[i]=(nums[st.top()]);
            }
            st.push(i%n);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};