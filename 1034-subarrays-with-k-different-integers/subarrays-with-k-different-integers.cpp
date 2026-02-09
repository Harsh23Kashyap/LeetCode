class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        unordered_map<int,int> u;
        int i=0,j=0;
        int c=0;
        while(j<nums.size()){
            u[nums[j]]++;

            while(i<j and u.size()>k){
                u[nums[i]]--;
                if(u[nums[i]]==0)
                u.erase(nums[i]);
                i++;
            }
            c+=j-i+1;
            j++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-(k==1?0:atmostk(nums,k-1));
    }
};