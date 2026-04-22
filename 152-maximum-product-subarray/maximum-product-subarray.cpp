class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxProd = 1;
        int minProd = 1;
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int tempMax = maxProd;

            int ca = max({num, num * maxProd, num * minProd});
            int cb = min({num, num * tempMax, num * minProd});
            maxProd=ca,minProd=cb;
            
            ans = max(ans, maxProd);
        }

        return ans;
    }
};