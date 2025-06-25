class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> maxLargestLeft(nums.size(),0);
         vector<int> maxLargestRight(nums.size(),0);

         for(int i=1;i<nums.size();i++){
            maxLargestLeft[i]=max(maxLargestLeft[i-1],nums[i-1]);
         }
          for(int i=nums.size()-2;i>=0;i--){
            maxLargestRight[i]=max(maxLargestRight[i+1],nums[i+1]);
         }
        long long ans=0;
         for(int i=1;i<nums.size()-1;i++){
            long long check=maxLargestLeft[i]-nums[i];
            check*=maxLargestRight[i];
            ans=max(ans,check);
         }
         return ans;
        
    }
};