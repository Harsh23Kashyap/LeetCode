class Solution {
public:
    int minOperations(string s) {
        int curr=0;
        int inzero=0;
        for(auto it:s)
        {
            inzero+=(((it-'0')==curr)?0:1);
            curr=curr^1;
        }
        
        int inone=0;
        curr=1;
        for(auto it:s)
        {
            inone+=(((it-'0')==curr)?0:1);
             curr=curr^1;
        }
        // cout<<inzero<<" "<<inone<<endl;
        return min(inzero,inone);
    }
};