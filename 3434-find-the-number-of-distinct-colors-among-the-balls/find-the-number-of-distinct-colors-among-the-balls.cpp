class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> bc;
        
        unordered_map<int,int> gc;
        
        vector<int> ans;
        int distinct=0;
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            int currb=0;
            if(bc.find(ball)!=bc.end())
               currb=bc[ball];
            if(currb!=0)
            {
                gc[currb]--;
                if(gc[currb]==0)
                    distinct--;
            }
            if(gc[color]==0)
                distinct++;
            
            gc[color]++;
            bc[ball]=color;
            ans.push_back(distinct);
        }
        return ans;
    }
};