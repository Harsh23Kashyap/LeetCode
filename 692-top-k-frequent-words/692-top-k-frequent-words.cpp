class Solution {
public:
    static bool sortgreat(const pair<int,string>& p1,const pair<int,string>& p2)
    {
        if(p1.first>p2.first)
            return true;
        else if(p1.first==p2.first)
        {
            if(p1.second<=p2.second)
                return true;
            else
                return false;
        }
        else
            return false;
            
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        vector<pair<int,string>> v;
        for(auto i:m)
        {
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end(),sortgreat);
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
        
    }
};