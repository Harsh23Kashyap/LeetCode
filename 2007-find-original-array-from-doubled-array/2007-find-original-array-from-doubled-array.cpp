class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        sort(changed.begin(),changed.end());
        multiset<int> s;
        int count=0;
        vector<int> ans;
        for(int i:changed)
        {
            if(i!=0)
                s.insert(i);
            else
                count++;
        }
        if(count%2!=0)
            return {};
        else
            ans.insert(ans.begin(),count/2,0);
         
        for(auto it:s)
        {
            // cout<<it<<endl;
           
            if(s.find(it*2)!=s.end())
            {
                ans.push_back(it);
                s.erase(s.find(it*2));
            }
            else
                return {};
        }
        return ans;
        
    }
};