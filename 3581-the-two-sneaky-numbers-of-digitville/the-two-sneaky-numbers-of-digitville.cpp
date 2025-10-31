class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> u;
        int prev=-1;
        for(auto it:nums){
            u[it]++;
            if(u[it]==2){
                if(prev==-1)
                    prev=it;
                else
                    return {prev,it};
            }
        }
        return {-1};
    }
};