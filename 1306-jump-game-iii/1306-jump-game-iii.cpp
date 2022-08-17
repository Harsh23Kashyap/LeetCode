class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
       queue<int> q;
        vector<bool> dp(arr.size(),0);
        q.push(start);
        dp[start]=true;
        while(!q.empty())
        {
            int ind=q.front();
            dp[ind]=true;
            q.pop();
            if(arr[ind]==0)
                return true;
            if(ind-arr[ind]>=0 and dp[ind-arr[ind]]==false)
                q.push(ind-arr[ind]);
            if(ind+arr[ind]<arr.size() and dp[ind+arr[ind]]==false)
                q.push(ind+arr[ind]);
                
            
        }
        
        return false;
    }
};