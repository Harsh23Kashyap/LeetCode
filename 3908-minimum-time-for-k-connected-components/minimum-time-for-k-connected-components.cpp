class Solution {
public:
class DSU
{
    public:
    vector<int> parent;
    vector<int> rank;
    int comp;
    DSU (int n){
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        comp=n;
    }

    int find(int x){
        if(parent[x]==x)
        return x;

        return parent[x]=find(parent[x]);
    }
    bool unite(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py)
        return false;
        if(rank[px]<rank[py]){
            rank[py]+=rank[px];
            parent[px]=py;
        }
        else{
            rank[px]+=rank[py];
            parent[py]=px;
        }
        comp--;
        return true;
    }
};
static bool cmp(vector<int> &a, vector<int> &b){
    return a[2]>b[2];
}
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if(edges.size()==0)
        {
            if(n>=k)
            return 0;
            return -1;
        } 
        int l=0;
        sort(edges.begin(),edges.end(),cmp);

        int h=edges[0][2];
    int ans=h;
        while(l<=h){
            int m=l+(h-l)/2;
            // cout<<m<<endl;
            DSU dsu(n);
            for(int i=0;i<edges.size();i++){
                if(edges[i][2]<=m)
                break;

                dsu.unite(edges[i][0],edges[i][1]);
            }

            if(dsu.comp>=k)
            {
                ans=m;
                h=m-1;
            }
            else
            l=m+1;
        }
        return ans;
    }
};