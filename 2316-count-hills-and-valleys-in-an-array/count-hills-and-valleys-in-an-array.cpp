class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int prev=nums[0],s=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
            continue;
            if(nums[i]>prev and nums[i]>nums[i+1]){
                cout<<"a"<<nums[i]<<endl;
                s++;

            }
            else if (nums[i]<prev and nums[i]<nums[i+1]){
                cout<<nums[i]<<endl;
                s++;
            }
            
             prev=nums[i];
        }
        return s;
    }
};