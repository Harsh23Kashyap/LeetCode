class Solution {
public:
    int findClosest(int x, int y, int z) {
        return ((abs(z-x)>=abs(y-z))?((abs(z-x)==abs(y-z))?0:2):1);
    }
};