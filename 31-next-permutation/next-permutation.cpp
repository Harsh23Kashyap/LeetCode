class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 and nums[i-1]>=nums[i])
        i--;
        
        if(i==0)
        {
            sort(nums.begin(),nums.end());
            return ;
        }
        i--;
        cout<<i<<endl;
        int j=nums.size()-1;
        while(j>i){
            if(nums[j]>nums[i])
            break;
            j--;
        }
        int t=nums[j];
        nums[j]=nums[i],nums[i]=t;
        // swap(&nums[j],&nums[i]);

        sort(nums.begin()+i+1,nums.end());
        return ;
    }
};