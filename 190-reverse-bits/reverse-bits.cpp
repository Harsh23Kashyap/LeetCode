class Solution {
public:
    int reverseBits(int n) {
        unsigned int c=0;
       for(int i=0;i<32;i++){
            int sb=(1<<i) & n;
            // cout<<sb<<endl;
            c=(c<<1) | (sb > 0);
       }
       return c;
    }
};