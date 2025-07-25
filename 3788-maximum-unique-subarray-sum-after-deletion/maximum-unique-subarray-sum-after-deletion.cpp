class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans=0;
        int maxi=*max_element(nums.begin(),nums.end());

        if(maxi<0){
            return maxi;
        }

        int s=0;
        unordered_set<int> u;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 and u.find(nums[i])==u.end()){
            u.insert(nums[i]);
            s+=nums[i];
            }
        }
        return s;
    }
};