class Solution {
public:
    int minMoves(int target, int md) 
    {
        //if(target==1) return 1;
        if(md==0) return target-1;
        int moves=0;
        while(target>1 and md-->0)
        {
            if(target%2!=0)
            {
                target--;
                moves++;
            }
            if(target==1) return moves;
            target/=2;
            moves++;
            if(target==1) return moves;
            
        }
        if(target>0) moves+=(target-1);
        
        return moves;
    }
};