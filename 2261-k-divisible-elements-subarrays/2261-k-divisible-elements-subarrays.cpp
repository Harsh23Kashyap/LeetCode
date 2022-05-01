class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n=nums.size(), res=0;
        unordered_set<string> all; 
        for (int i=0; i<n; i++) 
        {
            for (int len=i; len<=n; len++) 
            {
                int cnt=0;
                string currSubString; 
                for (int j=i; j<len; j++) 
                {
                    currSubString.push_back(nums[j]);
                    if (nums[j] % p == 0)  cnt++;
                }
                
                if (cnt <= k and !currSubString.empty())    
                    all.insert(currSubString);
            }
        }
        return size(all);
    }
};