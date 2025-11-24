class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num=0;
     vector<bool> ans;
        for(auto it:nums){
            num=((num<<1) | it)%5;
            if(num%5==0)
                ans.push_back(true);
            else
                 ans.push_back(false);

        }
        return ans;
    }
};