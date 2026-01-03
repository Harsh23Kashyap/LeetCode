class Solution {
public:
    int numOfWays(int n) {
        
        long long xyx=6, xyz=6, m=1e9+7;

        for(int i=2;i<=n;i++){
            long long new_xyx= (3*xyx+2*xyz)%m;
            long long new_xyz= (2*xyx+2*xyz)%m;

            xyx=new_xyx;
            xyz=new_xyz;
        }
        return (xyx+xyz)%m;
    }
};


/*
12 total 
6 each

n==1 is 12 6 each

now

for 

RYR
fr diff we have 2 options GRY or YRG

for same whavs GRG YRY YGY only 3

RGY
for diff we have 2 options YRG GYR
for same we have GRG GYG can bew 3


*/
