class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int c=0;
        int xored=x^y;
        while(xored>0)
        {
            c++;
            xored=xored&(xored-1);
        }
        return c;
    }
};

// 1001001
// 1011101