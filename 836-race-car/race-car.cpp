class Solution {
public:
  unordered_map<int, int> memo;
    int racecar(int target) {
        if (memo.count(target)) 
            return memo[target];
        
        int n = 1;
        
        while ((1 << n) - 1 < target) 
            n++;
        int overshoot=(1 << n) - 1;
        if (overshoot == target) {
            memo[target] = n;
            return n;
        }
        int res=INT_MAX;
        if(memo.find(overshoot - target)==memo.end())
             res = min(res, n + 1 + racecar(overshoot-target));
        else
            res = min(res, n + 1 + memo[overshoot-target]);

        int undershoot = (1 << (n - 1)) - 1;
        
        for (int m = 0; m < n - 1; ++m) {
            int forwardDist = undershoot;

            int backDist = (1 << m) - 1; 

            int steps = (n - 1) + 1 + m + 1 + racecar(target - forwardDist + backDist);
             res = min(res, steps);
        }
         memo[target] = res;
        return res;
        

    }
};