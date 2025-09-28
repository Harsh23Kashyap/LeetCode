class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int largest=0;

        for(int i=nums.size()-3;i>=0;i--){
            // for(int j=i+1;j<nums.size();j++){
            //     for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[i+1]>nums[i+2] and nums[i]+nums[i+2]>nums[i+1] and nums[i+1]+nums[i+2]>nums[i]){
                        largest=max(largest,nums[i]+nums[i+1]+nums[i+2]);
                    }
                // }
            }
        //     int j=i+1,k=nums.size()-1;
        //     while(j<k)
        //     {
        //          if(nums[i]+nums[j]>nums[k] and nums[i]+nums[k]>nums[j] and nums[j]+nums[k]>nums[i]){
        //              largest=max(largest,nums[i]+nums[j]+nums[k]);
        //             }
        //             else 
        //                 break;
        //             j++,k--;
        //     }
        // }
        return largest;
    }
};