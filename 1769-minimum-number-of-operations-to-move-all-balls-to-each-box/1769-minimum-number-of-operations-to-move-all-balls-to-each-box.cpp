class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        vector<int> ans;
        for(int i=0;i<boxes.size();i++)
        {
            int sum=0;
            for(int j=0;j<boxes.size();j++)
            {
                sum+=(boxes[j]=='1')?(abs(i-j)):0;
            }
            ans.push_back(sum);
        }
        return ans;
        
    }
};