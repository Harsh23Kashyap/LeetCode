class Solution {
public:
    int Winner(vector<int> &v, int k, int start)
    {
        if(v.size()==1)
            return v[0];
        //cout<<start<<endl;
        int ban= (start+k)%v.size();
        int val=v[ban];
        cout<<val<<endl;
        auto it=find(v.begin(),v.end(),val);
        v.erase(it);
        return Winner(v,k,ban-1);
        
    }
    int findTheWinner(int n, int k) 
    {
        vector<int> v;
        for(int i=0;i<n;i++)
            v.push_back(i+1);
        return Winner(v,k,-1);
    }
};