class Solution {
public:
    int mirrorDistance(int n) {
        string no=to_string(n);
        reverse(no.begin(),no.end());
        return abs(stoi(no)-n);
    }
};