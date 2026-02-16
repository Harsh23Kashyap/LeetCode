class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> out;
        long long a=1;
        for(auto it:nums){
            a*=it;
            ans.push_back(a); 
        }
        long long b=1;
        for(int i=nums.size()-1;i>0;i--)
        { 
           out.push_back(ans[i-1]*b);
            b*=nums[i];
        }
        out.push_back(b);
        reverse(out.begin(),out.end());
        return out;
    }
};