class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int least=INT_MAX;
        for(int i=0;i<arr.size()-1;i++)
            least=min(least,abs(arr[i+1]-arr[i]));
        
        vector<vector<int>> ans;
        
        for(int i=0;i<arr.size()-1;i++)
        {
            if(abs(arr[i+1]-arr[i])==least)
                ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
        
    }
};