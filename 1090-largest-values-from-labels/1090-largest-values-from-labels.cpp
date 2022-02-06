class Solution {
public:
    static bool cmp(const pair<int,int>& a,const pair<int,int>& b)
    {
        return a.second>b.second;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>> v;
        for(int i=0;i<labels.size();i++)
            v.push_back(make_pair(labels[i],values[i]));
        
        sort(v.begin(),v.end(),cmp);
            
        unordered_map<int,int> m;
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            m[v[i].first]++;
            if(m[v[i].first]<=useLimit)
            {
                sum+=v[i].second;
                numWanted--;
            }
            if(numWanted==0)
                break;
        }
        return sum;
    }
};