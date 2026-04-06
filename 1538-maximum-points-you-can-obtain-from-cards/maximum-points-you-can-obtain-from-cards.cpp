class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        if(k==cp.size())
            return accumulate(cp.begin(),cp.end(),0);
        vector<int> ps;

        for(int i=0;i<cp.size();i++)
            ps.push_back(cp[i]+((i==0)?0:ps.back()));

        int maxi=0;
        for(int op=0;op<=k;op++){
            //take op from beginninga nd k-op from end
            int begin=0,end=0;
            int fromend=k-op;
            if(op!=0)
                begin=ps[op-1];
            if(op!=k)
                end=ps.back()-ps[ps.size()-fromend-1];

            cout<<begin+end<<endl;
            maxi=max(maxi,begin+end);
        }
        return maxi;
        
    }
};