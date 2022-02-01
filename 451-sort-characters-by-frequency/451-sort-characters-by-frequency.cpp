class Solution {
public:
    static bool sortgreat(const pair<int,int>& p1,const pair<int,int>& p2)
    {
        return p1.first>p2.first;
    }
    string frequencySort(string s) 
    {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto i:m)
        {
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end(),sortgreat);
        string ans;
        for(int i=0;i<v.size();i++)
        {
            //cout<<v[i].second<<" "<<v[i].first<<endl;
            string curr="";
            curr.append(v[i].first,v[i].second);
            ans+=curr;
        }
        return ans;
    }
};