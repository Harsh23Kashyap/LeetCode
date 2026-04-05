class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0,d=0;
        for(auto it:moves){
            switch(it){
                case 'U':
                    d--;
                    break;
                
                case 'D':
                    d++;
                    break;
                case 'L':
                    r--;
                    break;
                case 'R':
                    r++;
                    break;
            }
        }
        return r==0 and d==0;
    }
};