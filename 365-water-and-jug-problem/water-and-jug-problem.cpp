class Solution {
public:
int getGCF(int a, int b) {
    if (b == 0) 
        return a;
    return getGCF(b, a % b);
}

    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target)
        return 0;

        return target%getGCF(x,y)==0;
    }
};