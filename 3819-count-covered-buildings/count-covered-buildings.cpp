class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        unordered_map<int,vector<int>> dx;
        unordered_map<int,vector<int>> dy;

        for(auto it:b){
            dx[it[0]].push_back(it[1]);
            dy[it[1]].push_back(it[0]);
        }
        for(auto it:dx){
            vector<int> kk= it.second;
            sort(kk.begin(),kk.end());
            dx[it.first]=kk;
        }
        for(auto it:dy){
            vector<int> kk= it.second;
            sort(kk.begin(),kk.end());
            dy[it.first]=kk;
        }

        int ans=0;

        for(auto it:b){
            int x=it[0],y=it[1];

            auto ub = upper_bound(dx[x].begin(), dx[x].end(), y); 
            if(ub==dx[x].end())
                continue;
            auto lb = lower_bound(dx[x].begin(), dx[x].end(), y);
            if (lb == dx[x].begin())
            continue;

            ub = upper_bound(dy[y].begin(), dy[y].end(), x); 
            if(ub==dy[y].end())
                continue;
             lb = lower_bound(dy[y].begin(), dy[y].end(), x);
            if (lb == dy[y].begin())
            continue;
            ans++;

        }
        return ans;
    }
};