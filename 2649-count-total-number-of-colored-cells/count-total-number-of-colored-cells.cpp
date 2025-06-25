class Solution {
public:
    long long coloredCells(int n) {
        long long c=1;
        long long add=4;
        long long factor=4;
        for(int i=2;i<=n;i++){
            c+=add;
            add+=factor;
        }
        return c;
    }
};

// /*
// 1=1
// 2=5
// 3=13
// 4=25
// 5=41
// 6=61

// /*