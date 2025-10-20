class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto it:operations)
            x+=(it[0]=='+' or it[2]=='+')?1:-1;
        return x;
    }
};