class Solution {
public:
    int bulbSwitch(int n) 
    {
        int i;
        for(i=1;i*i<=n;i++);
        return i-1;
    }
};