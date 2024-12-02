class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> od(n,0);
        for(auto it:edges)
            od[it[1]]++;
        
        int bestie=-1;
        
        for(int i=0;i<od.size();i++){
            if(od[i]==0){
                if(bestie!=-1)
                    return -1;
                bestie=i;
            }
        }
        return bestie;
    }
};