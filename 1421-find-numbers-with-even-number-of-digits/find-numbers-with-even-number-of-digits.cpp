class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int c=0;
        for(auto it:nums){
            c+=(to_string(it).length()%2==0);
        }
        return c;
    
    }
};