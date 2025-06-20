class Solution {
public:
    long long calculateScore(vector<string>& ins, vector<int>& values) {
        unordered_set<int> vis;
        int ind=0;
        long long ans=0;
        while(ind<ins.size() and vis.find(ind)==vis.end()){
            vis.insert(ind);
            if(ins[ind]=="add"){
                ans+=values[ind];
                ind++;

            }
            else{
                ind+=values[ind];
            }
        }
        return ans;
    }
};