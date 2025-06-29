class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        if(nums.size()<=2)
        {
            if(nums.size()==1)
            return 0;
            if(nums[0]==nums[1])
            return 1;
            else
            return 0;
        }

        
        unordered_map<int,int> u;
        unordered_set<int> s;
        for(auto it:nums){
            u[it]++;
            if(u[it]>1){
                s.insert(it);
            }
        }
        int c=0;
        int i=0;
        for(;i<nums.size()-2;i+=3)
        {
            if(s.size()==0){
                return c;
            }

            u[nums[i]]--;
            u[nums[i+1]]--;
            u[nums[i+2]]--;

            if(u[nums[i]]<=1){
                s.erase(nums[i]);

            }

            if(u[nums[i+1]]<=1){
                s.erase(nums[i+1]);

            }
            if(u[nums[i+2]]<=1){
                s.erase(nums[i+2]);

            }


            c++;
        }
        
        return s.size()==0?c:c+1;
    }
};