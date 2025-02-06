class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int forone=8;
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
            {
                u[nums[i]*nums[j]]++;
            }
        }

        int c=0;
        for(auto it:u){
            if(it.second>1)
            {
                int t=it.second-1;
                t=((t+1)*t)/2;
                c=c+t*8;
            }
            
        }
        return c;
    }
};