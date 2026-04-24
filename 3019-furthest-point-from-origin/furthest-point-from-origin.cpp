class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dash=0,l=0,r=0;
        for(auto it:moves)
        {
            if(it=='L')
            l++;
            else if(it=='R')
            r++;
            else
            dash++;
        }
        return abs(l-r)+dash;
    }
};