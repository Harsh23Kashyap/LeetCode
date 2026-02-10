class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool p1=false, p2=false, p3=false;
        for(auto it:triplets){
            if(it[0]==target[0] and it[1]<=target[1] and it[2]<=target[2])
            p1=true;
            if(it[0]<=target[0] and it[1]==target[1] and it[2]<=target[2])
            p2=true;
            if(it[0]<=target[0] and it[1]<=target[1] and it[2]==target[2])
            p3=true;
        }
        return p1 and p2 and p3;
    }
};