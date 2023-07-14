class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // vector<int> dp(arr.size(),1);
        unordered_map<int,int> u;
        u[arr[0]]=1;
        int maxi=1;
        for(int i=1;i<arr.size();i++)
        {
            int p=arr[i]-difference;
            // cout<<p<<" ";
            if(u.find(p)!=u.end())
            {
                u[arr[i]]=1+u[p];
                maxi=max(maxi,u[arr[i]]);
            }
            else
                u[arr[i]]=1;
        }
        return maxi;
    }
};