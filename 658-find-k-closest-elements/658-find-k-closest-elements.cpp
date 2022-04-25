class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++)
        {
            v.push_back(make_pair(abs(arr[i]-x),arr[i]));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout<<v[i].second<<" - "<<v[i].first<<endl;
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};