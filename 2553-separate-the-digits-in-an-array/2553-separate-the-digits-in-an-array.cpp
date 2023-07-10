class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums)
        {
            string s=to_string(i);
            for(int i=0;i<s.size();i++)
            {
                ans.push_back(s[i]-'0');
            }
            
        }
        return ans;
    }
};