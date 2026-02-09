class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i-1>=0 and nums[i-1]>=nums[i])
        i--;
        if(i==0)
        {
            sort(nums.begin(),nums.end());
            return ;


        }

        // cout<<i-1<<" "<<nums[i-1]<<endl;
        int j=nums.size()-1;
        while(j>=i and nums[i-1]>=nums[j])
        j--;
        
    // cout<<j<<" "<<nums[j]<<endl;
        swap(nums[i-1],nums[j]);

        reverse(nums.begin()+i,nums.end());
        return ;
    }
};


// 1  4 2 5 3  1 