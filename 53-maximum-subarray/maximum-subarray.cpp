class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0,m=INT_MIN;
        for(auto it:nums){
            s+=it;
            m=max(m,s);
            if(s<0)
            s=0;
            
        }
        return m;
    }
};