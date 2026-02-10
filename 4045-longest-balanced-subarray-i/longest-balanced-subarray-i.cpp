class Solution {
public:
    bool possible(vector<int>& nums, int m){ 
        unordered_map<int,int> u;
        int even=0,odd=0;
        for(int i=0;i<m;i++){
            if(nums[i]%2==0){
                if(u.find(nums[i])==u.end())
                even++;
            }
            else{
                if(u.find(nums[i])==u.end())
                odd++;
            }
            u[nums[i]]++;
        }
        if(even==odd)
            return true;
        int i=m;

        while(i<nums.size()){ 
            if(nums[i]%2==0){
                if(u.find(nums[i])==u.end())
                even++;
            }
            else{
                if(u.find(nums[i])==u.end())
                odd++;
            }
            u[nums[i]]++;
            u[nums[i-m]]--;  
             if(nums[i-m]%2==0){ 
                if(u[nums[i-m]]==0){
                u.erase(nums[i-m]);
                even--;
                }
            }
            else{ 
                 if(u[nums[i-m]]==0){ 
                u.erase(nums[i-m]);
                odd--;
                 }
            }
             if(even==odd)
            return true;
            i++;
        }
        return false;



    }
    int longestBalanced(vector<int>& nums) {
        int h=nums.size();
        int ans=0;
        while(h>=0)
        {
            if(possible(nums,h)){
                ans=h;
                return ans;
            }
            else
            h=h-1;
        }
        return -1;
    }
};