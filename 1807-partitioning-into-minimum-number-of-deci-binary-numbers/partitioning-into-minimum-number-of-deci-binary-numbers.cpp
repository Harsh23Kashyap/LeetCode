class Solution {
public:
    int minPartitions(string s) {
        
        sort(s.begin(),s.end());
        return s.back()-'0';
    }
};