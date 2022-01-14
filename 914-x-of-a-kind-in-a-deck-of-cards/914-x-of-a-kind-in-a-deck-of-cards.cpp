class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        if(deck.size()==1) return false;
        unordered_map<int,int>m;
        for(auto i:deck)
            m[i]++;
        int hcf=(m[deck[0]]);
        for(auto u: m)
            hcf=__gcd(hcf,u.second);
        return hcf>=2;
    }
};