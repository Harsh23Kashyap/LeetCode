class Solution {
public:
unordered_set<int> r;
unordered_set<int> c;
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        reverse(queries.begin(),queries.end());
        long long  total=0;

        for(auto it:queries){
            int type=it[0],index=it[1],val=it[2];

            if(type==1){
                if(c.find(index)!=c.end())
                continue;
                int sz=r.size();
                c.insert(index);
                total+=(n-sz)*val;
            }
            if(type==0){
                if(r.find(index)!=r.end())
                continue;
                int sz=c.size();
                r.insert(index);
                total+=(n-sz)*val;
            }
            cout<<total<<endl;
        }
        return total;
    }
};