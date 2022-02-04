class Solution {
public:
    static bool sortfirst(const pair<int,int>& a,const pair<int,int>& b )
    {
        return a.first<b.first;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int,int> u;
        for(int i:arr)
            u[i]++;
        vector<pair<int,int>> ans;
        for(auto i:u)
            ans.push_back(make_pair(i.second,i.first));
        
        sort(ans.begin(),ans.end(),sortfirst);
        int i;
        for(i=0;i<ans.size();i++)
        {
            if(k==0)
                break;
            else if(k<0)
            {
                i--;
                break;
            }
            else
            {
                k-=ans[i].first;
            }
        }
        if(ans.size()==i)
        {
            if(k==0)
                return 0;
            else if(k<0)
                return 1;
        }
        return ans.size()-i;
    }
};