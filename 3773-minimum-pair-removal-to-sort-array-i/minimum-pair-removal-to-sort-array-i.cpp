class Solution {
public:
bool nondecreasing(vector<int>& nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
             cout<<endl;
        return false;
        }
    }

    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int a=0;
        
        while(!nondecreasing(nums)){
            a++;
            long long mini=INT_MAX;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mini)
                mini=nums[i]+nums[i+1];
            }
            vector<int> copy;
            bool found=false;
            int i = 0;
            while (i < nums.size()) {
                if (!found and i + 1 < nums.size() and nums[i] + nums[i+1] == mini) {
                    copy.push_back(nums[i] + nums[i+1]);
                    found = true;
                    i += 2; 
                } else {
                    copy.push_back(nums[i]);
                    i++;
                }
            }

            nums=copy;


        }
        return a;

    }
};


/*
2,2,-1,3,-2,2,1,1,1,-1
2,2,-1,3,0,1,1,1,-1


*/