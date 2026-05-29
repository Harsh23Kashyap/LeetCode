class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;

        for(auto it:nums){
            int z=0,c=it;;
            while(c>0){
                z+=(c%10);
                c/=10;
            }
            mini=min(mini,z);
        }
        return mini;
    }
};