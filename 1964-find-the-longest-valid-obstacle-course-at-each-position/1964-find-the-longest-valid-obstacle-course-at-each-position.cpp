class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> ans;
        ans.push_back(1);
        vector<int> dp;
        dp.push_back(obstacles[0]);
        for(int i=1;i<obstacles.size();i++)
        {
            if(obstacles[i]>=dp[dp.size()-1])
            {
                dp.push_back(obstacles[i]);
                ans.push_back(dp.size());
            }
            else
            {
                int pos=upper_bound(dp.begin(),dp.end(),obstacles[i])-dp.begin();
                //cout<<dp.size()<<" "<<i<<" "<<pos<<endl;
                dp[pos]=obstacles[i];
                ans.push_back(pos+1);
            }
        }
        return ans;
        
    }
};