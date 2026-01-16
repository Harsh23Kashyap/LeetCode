class Solution {
public:
    unordered_set<int> allVCalues(vector<int>& a, int c){
         unordered_set<int> u;
         u.insert(c-1);
         for(int i=0;i<a.size();i++){
            u.insert(a[i]-1);
            u.insert(c-a[i]);
            for(int j=0;j<a.size();j++){
                if(i==j)
                continue;
                // cout<<abs(a[i]-a[j])<<" ";
                u.insert(abs(a[i]-a[j]));
            }
         }
        //  cout<<endl;
         return u;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
        unordered_set<int> r=allVCalues(vFences,n);
        unordered_set<int> c=allVCalues(hFences,m);
        long long maxi=0;
        bool found=false;
        for(auto it:r){
            // cout<<it<<endl;
            if(c.find(it)!=c.end())
            {
                found=true;
                long long val=(1ll*it*it);
                maxi=max(maxi,val);
            }
        }
        if(!found)
        return -1;
        return maxi%mod;

    }
};