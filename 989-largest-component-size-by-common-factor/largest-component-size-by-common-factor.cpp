class Solution {
public:

struct DSU 
{
    vector<int> par, rank;
    DSU(int n)
    {
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
        rank.assign(n,1);
    }  
    
    int find(int x) { 
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }
    
    void unite(int a, int b) 
    {
        a = find(a); 
        b = find(b);
        if (a == b) 
            return;
        
        if (rank[a] <= rank[b]) {
            rank[b]+=rank[a];
            par[a]=b;
        }
        else{
             rank[a]+=rank[b];
            par[b]=a;
        }
      
    }
};

    int largestComponentSize(vector<int>& signatures) {
        int r = *max_element(signatures.begin(), signatures.end()); 
        

        vector<int> spf(r+1,0);
        iota(spf.begin(),spf.end(),0);
        for(int i=2;i*i<=r;i++){
            if(spf[i]!=i)
                continue;

            for(int j=i*i;j<=r;j+=i){
                if(spf[j]==j)
                    spf[j]=i;
            }
        }


        DSU dsu(signatures.size());
        unordered_map<int,int> u;


        for(int i=0;i<signatures.size();i++){
            int x=signatures[i];
            if(x<=1)
                continue;
            
            while(x>1){
                int p=spf[x];
                if(!u.count(p) ){
                    u[p]=i;

                }
                else{
                    dsu.unite(i,u[p]);
                }

                while(x%p==0)
                    x/=p;
            }
        }


        int ans=0;

        for(int i=0;i<signatures.size();i++){ 
            int pa=dsu.find(i);
            if(dsu.rank[pa]>ans){
                ans=dsu.rank[pa];
            }
        }
        return ans; 
    }
};